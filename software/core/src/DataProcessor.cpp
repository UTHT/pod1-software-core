<<<<<<< HEAD
#include <vector>

#include "DataProcessor.hpp"

DataProcessor::DataProcessor(){
}

DataProcessor::DataProcessor(const std::vector<Channel> &channels){
        this->channels = channels;
}

DataProcessor::~DataProcessor(){
}

void DataProcessor::process(){
    for(int i =0; i < this->channels.size(); ++i){
        // get information from relevant channels
        //
    }
}
