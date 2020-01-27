#include "DataProcessor.hpp"

DataProcessor::DataProcessor(const std::vector<Channel> &channels){
        this->channels = channels;
}

DataProcessor::~DataProcessor(){
}

float DataProcessor::process(){
    for(int i =0; i < this->channels.size(); ++i){
        // get information from relevant channels
        //
    }
    return 0;
}
