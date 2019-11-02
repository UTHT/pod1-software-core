#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>

class DataProcessor{
    protected:
        std::vector<Channels> channelList;

    public:
        DataProcessor(const std::vector<Channels> & list);   //user-defined constructor 
        virtual ~DataProcessor();       //destructor
        int run(); //iterate through all channels in channelList for raw data                   
        virtual float process() = 0;      //calculates and returns data specific for each instantiation
};


#endif