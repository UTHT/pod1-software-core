#include "DataProcessor.hpp"
#include <vector>

DataProcessor::DataProcessor(const std::vector<Channels> &channels){
        this->channels = channels;
}

DataProcessor::~DataProcessor(){

}

int DataProcessor::run(){
    for(int i =0; i < channels.size(); ++i){
        // get information from relevant channels
        //
    }
}
