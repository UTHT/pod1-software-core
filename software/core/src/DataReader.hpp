class DataReader {
  private:
   int pin;
   void setPin(int pin) {pin = pin;}
   struct *data;

  public:
   bool get(const struct timeval timeout, int pin, class DataReader sensorName);
   bool pub(const struct timeval timeout);
   
};

