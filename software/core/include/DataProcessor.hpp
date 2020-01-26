#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include "Channel.hpp"

class DataProcessor{
    protected:
        std::vector<Channel> channels;

    public:
        DataProcessor(const std::vector<Channel> & channels);   //user-defined constructor
        virtual ~DataProcessor();       //destructor
        virtual float process() = 0;      //calculates and returns data specific for each instantiation
};


#endif
