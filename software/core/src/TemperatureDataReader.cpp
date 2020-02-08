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
    void TemperatureDataReader::readTemperature(double voltageInputDC, double offset){
        //Need to find offset + DC Voltage input value (could possibly be a parameter).

        int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
        int sensorInput;    //The variable we will use to store the sensor input
        double temp;        //The variable we will use to store temperature in degrees. 
     
        // put your main code here, to run repeatedly: 
        sensorInput = analogRead(A0);        //read the analog sensor and store it
        //analog output between 4 & 20

        temp = (double)sensorInput / 1024;   //find percentage of input reading
        temp = temp * voltageInputDC;                     //multiply by 5V to get voltage
        temp = temp - offset;                   //Subtract the offset 
        temp = temp * 100;                   //Convert to degrees (milli volts to celsius)
        //this conversion works for milivolts to celsius. We need to take in milliamps instead of millivolts.  

        temperature = temp; //updates object's value of temperature

    



}
