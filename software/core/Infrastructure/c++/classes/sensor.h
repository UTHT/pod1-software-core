#include <iostream>
#include <vector>
 
using namespace std;

class Sensor {
    protected:

        string _name;
        int _value;


    public:

        Sensor( string name, int value): _name(name), _value(value) {};

        void setName(string newName){
            _name = newName;
        }

        void setValue( int newValue){
            _value = newValue;
        }

        string getName(){
            return _name;
        }

        int getValue(){
            return _value;
        }

        string toString(){
            return (
            "{'name':'" + _name + "','value':" + to_string(_value) + "}"
            );
        }
};


class SpeedSensor: public Sensor{
    public:
        SpeedSensor( string name, int value): Sensor( name, value) {};
};

class TemperatureSensor: public Sensor{
    public:
        TemperatureSensor( string name, int value): Sensor( name, value) {};    
};

class BatterySensor : public Sensor{
    public:
        BatterySensor( string name, int value): Sensor( name, value) {};
};

class BrakeSensor : public Sensor{
    public:
        BrakeSensor( string name, int value): Sensor( name, value) {};
};

class PositionSensor {
    protected:
        int _x;
        int _y;
    
    public:
        PositionSensor(){};
        PositionSensor(int x, int y): _x(x), _y(y) {};

        void setX(int x){
            _x = x;
        }

        void setY( int y){
            _y = y;
        }

        int getX(){
            return _x;
        }

        int getY(){
            return _y;
        }

        string toString(){
            return (
                "[" + to_string(_x) + "," + to_string(_y) + "]"
            );
        }
};

class Bundler {
    protected:
        vector<SpeedSensor> _speedSensors;
        vector<TemperatureSensor> _tempSensors;
        vector<BatterySensor> _batteryensors;
        vector<BrakeSensor> _brakesSensors;
        PositionSensor _positionSensors;
    public:

        Bundler(vector<SpeedSensor> speedSensors,vector<TemperatureSensor> tempSensors,
        vector<BatterySensor> batteryensors,vector<BrakeSensor> brakesSensors,  PositionSensor positionSensors
        ) 
        {
            _speedSensors = speedSensors;
            _tempSensors = tempSensors;
            _batteryensors = batteryensors;
            _brakesSensors = brakesSensors;
            _positionSensors = positionSensors;
        }

        string toString(){
            vector<string> outputString;
            
            outputString.push_back("{'eventType':'relay','clientType':'odroid','data':{"); // !!Important

            // For Speed Sensors
            outputString.push_back("'speed':[");
            for (auto i = 0; i<this->_speedSensors.size(); i++){
                // If it is the first element, we dont want to append comma in the starting
                if (i==0){
                    outputString.push_back(this->_speedSensors[i].toString());
                }
                else {
                    outputString.push_back("," + this->_speedSensors[i].toString());
                }
            }

            //Temperature Sensors
            outputString.push_back("],'temperatures':[");
            for (int i = 0; i<this->_tempSensors.size(); i++){
                // If it is the first element, we dont want to append comma in the starting
                if (i==0){
                    outputString.push_back(this->_tempSensors[i].toString());
                }
                else {
                    outputString.push_back("," + this->_tempSensors[i].toString());
                }
            }

            // For Brake Sesnsors
            outputString.push_back("],'brakes':[");
            for (int i = 0; i<this->_brakesSensors.size(); i++){
                // If it is the first element, we dont want to append comma in the starting
                if (i==0){
                    outputString.push_back(this->_brakesSensors[i].toString());
                }
                else {
                    outputString.push_back("," + this->_brakesSensors[i].toString());
                }
            }
            //For Battery Sensors
            outputString.push_back("],'battery':[");
            for (int i = 0; i<this->_batteryensors.size(); i++){
                // If it is the first element, we dont want to append comma in the starting
                if (i==0){
                    cout << this->_batteryensors[i].toString() << endl;
                    outputString.push_back(this->_batteryensors[i].toString());
                }
                else {
                    cout << this->_batteryensors[i].toString() << endl;
                    outputString.push_back("," + this->_batteryensors[i].toString());
                }
            }

            outputString.push_back("],'position':" + this->_positionSensors.toString());

            // and so on

            outputString.push_back("}}"); // !! Important
            return std::accumulate(outputString.begin(), outputString.end(), std::string(""));
        }

};