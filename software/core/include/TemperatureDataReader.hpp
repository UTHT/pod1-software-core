#ifndef TEMPERATURE_READER_HPP
#define TEMPERATURE_READER_HPP

#include "DataReader.hpp"

class TemperatureDataReader: public DataReader{
    private:
        //the temperature
        double temperature; 
        //both ends of the voltages 
        double max_volt; 
        double min_volt; 
        int analog_input; 

    public:
    //primary constructor
    // TemperatureDataReader::TemperatureDataReader(DataReader IOPin);
    TemperatureDataReader::TemperatureDataReader(
        double temp,
        double maxVolt, 
        double minVolt, 
        int analogInput, ):DataReader(IOPin);
    //destructor
    ~TemperatureDataReader();
    //reads the temperature and updates object
    void TemperatureDataReader::readTemperature(); 
};

#endif