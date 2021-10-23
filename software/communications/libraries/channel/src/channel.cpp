#include "channel.hpp"

unordered_map<string, Channel*> channel_map;
unordered_map<string, zcm_t*> zcm_transport_map;
mutex global_lock;

Channel::Channel(string channel_name, string serial_port, string arduino_id, double min_value, double max_value) {
    this->channel_name = channel_name;
    this->min_value = min_value;
    this->max_value = max_value;
    this->serial_port = serial_port;
    this->arduino_id = arduino_id;

    // Convert string to char*
    char* serial_port_c = new char[serial_port.length() + 1];
    strcpy(serial_port_c, serial_port.c_str());

    auto find_zcm = zcm_transport_map.find(serial_port);

    // Create zcm object if it has not been created before
    if (find_zcm == zcm_transport_map.end()) {
        zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port_c);
        zcm_t* zcm_created = zcm_create_from_trans(linux_cobs_serial_transport);

        this->zcm = zcm_created;
        zcm_transport_map[serial_port] = zcm_created;
    } else {
        this->zcm = find_zcm -> second;
    }

    delete [] serial_port_c;

    // Defaulted this to the current time
    time(&this->last_comm_time);

    channel_map[this->channel_name] = this;
}

// Should return an ENUM
int Channel::validateCurrentValue() {
    time_t current_comm_time; 

    // Update the current time 
    time(&current_comm_time); 

    this->lock.lock();
    // Get the difference between current time and the last communicated time
    double time_diff = difftime(current_comm_time, this->last_comm_time); 

    // Check time
    if (time_diff >= 60.0) {
        this->lock.unlock();
        return ChannelStatus::NO_COMMS;
    }

    // Check value within range
    for (int x = 0; x < this->current_values.size(); x++){
         if (this->current_values.at(x) < this->min_value || this->current_values.at(x) > this->max_value) {
            this->lock.unlock();
            return ChannelStatus::OUT_OF_RANGE;
        }
    }

    // TODO: (Maybe) Check the frequency of data 
    // 1) What are the acceptable bounds?

    // Default return value
    this->lock.unlock();
    return ChannelStatus::FUNCTIONING;
}

// This is a static function (instead of a method function)
void Channel::callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_array* msg, void* user) {
    string sensorName = msg->sensor;

    // Get the pointer to the channel
    string channelString(sensorName);

    auto find_channel = channel_map.find(channelString);

    if (find_channel == channel_map.end()) {
        return;
    }

    Channel* channelObj = find_channel -> second;
    cout << "Received message on channel: " << channelString << endl;

    // TODO: Should we return some ENUM here?
    if (channelObj == NULL) {
        return;
    }

    // TODO: channel_msg also includes arduino_id and sensor_id. Can we validate this before modifying the current_value?

    // Message type checking
    // Need to double check what typeid.name() returns for double and arrays
    // string sensorType(typeid(msg->sensor_value).name());
    
    global_lock.lock();

    channelObj->current_values.clear();
    channelObj->current_values.insert(channelObj->current_values.begin(), msg->data, msg->data + msg->sz);

    time(&channelObj->last_comm_time);

    cout << "Current Values: ";
    for (int i = 0; i < channelObj->current_values.size(); i++) {
        cout << channelObj->current_values.at(i) << ", ";
    }
    cout << endl;
    
    cout << "Units: " << msg->units << endl;
    cout << "Time received: " << channelObj->last_comm_time << endl;
    
    global_lock.unlock();
}

vector<double> Channel::getCurrentValues() {
    this->lock.lock();
    vector<double> current_vals = this->current_values;
    this->lock.unlock();

    return current_vals;
}

zcm_t* Channel::getZCM() {
    return this->zcm;
}
string Channel::getChannelName() {
    return this->channel_name;
}

channel_array_subscription_t* Channel::subscribeToChannel() { 
    return channel_array_subscribe(this->zcm, this->channel_name.c_str(), &callbackHandler, NULL);
}