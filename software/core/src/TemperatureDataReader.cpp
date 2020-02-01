#include "TemperatureDataReader.hpp"

 TemperatureDataReader::TemperatureDataReader(
        double temp,
        double maxVolt, 
        double minVolt, 
        int analogInput, ):DataReader(IOPin){

        temperature = temp;
        max_volt = maxVolt;
        min_volt = minVolt;
        analog_input = analogInput;
        }
    //destructor
    ~TemperatureDataReader();
    //reads the temperature and updates object
    void TemperatureDataReader::readTemperature(){

        int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
        int sensorInput;    //The variable we will use to store the sensor input
        double temp;        //The variable we will use to store temperature in degrees. 
     
        // put your main code here, to run repeatedly: 
        sensorInput = analogRead(A0);        //read the analog sensor and store it
        temp = (double)sensorInput / 1024;   //find percentage of input reading
        temp = temp * 5;                     //multiply by 5V to get voltage
        temp = temp - 0.5;                   //Subtract the offset 
        temp = temp * 100;                   //Convert to degrees 
        temperature = temp; //updates object's value of temperature
 
}
