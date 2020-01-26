#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include "Channels.hpp"

class DataProcessor{
    protected:
        std::vector<Channels> channels;

    public:
        DataProcessor(const std::vector<Channels> & channels);   //user-defined constructor
        virtual ~DataProcessor();       //destructor
        int run(); //iterate through all channels in channelList for raw data
        virtual float process() = 0;      //calculates and returns data specific for each instantiation
};


#endif
