#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include "Channel.hpp"

class DataProcessor{
    protected:
        std::vector<Channel> channel_list;

    public:
        DataProcessor();
        DataProcessor(const std::vector<Channel> & list);   //user-defined constructor
        virtual ~DataProcessor();       //destructor
        void run(); //iterate through all channels in channelList for raw data
        void process();      //calculates and returns data specific for each instantiation
};


#endif
