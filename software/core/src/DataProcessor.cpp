#include "../include/DataProcessor.hpp"
#include <vector>

DataProcessor::DataProcessor(const std::vector<Channels> &list){
        channelList = list;
}

DataProcessor::~DataProcessor(){

}

int DataProcessor::run(){
    for(int i =0; i < channelList.size(); ++i){
        // get information from relevant channels
        // 
    }
}
