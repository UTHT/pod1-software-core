#include <iostream>
 
using namespace std;

class Sensor {
    protected:

        string _name;
        int _value;


    public:

        Sensor( string name, int value): _name(name), _value(value) {};

        void setName(string newName){
            _name = newName;
        }

        void setValue( int newValue){
            _value = newValue;
        }

        string getName(){
            return _name;
        }

        int getValue(){
            return _value;
        }

        string toString(){
            return (
            "{'name':" + _name + ",'value':" + to_string(_value) + "}"
            );
        }
};


class SpeedSensor: public Sensor{

};

class TemperatureSensor: public Sensor{

};

class BatterySensor : public Sensor{

};

class BrakeSensor : public Sensor{

};

class PositionSensor : public Sensor{
    protected:
        int _x;
        int _y;
    
    public:
        PositionSensor(int x, int y): _x(x), _y(y) {};

        void setX(int x){
            _x = x;
        }

        void setY( int y){
            _y = y;
        }

        int getX(){
            return _x;
        }

        int getY(){
            return _y;
        }

        string toString(){
            return (
                "[" + to_string(_x) + "," + to_string(_y) + "]"
            );
        }
};