#include <iostream>

class FahrenheitSensor // Existing class
{
public:
  float getFahrenheitTemp() {
    float t = 132.0;
    // Some code
    return t;
  }
};

class Sensor {
public:
  virtual ~Sensor() = default;
  virtual float getTemperature() = 0;
};

class Adapter : public Sensor {
public:
  explicit Adapter(FahrenheitSensor *p) : p_fsensor(p) {
  }
  ~Adapter() override {
    delete p_fsensor;
  }
  float getTemperature() override {
    return float((p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0);
  }
private:
  FahrenheitSensor *p_fsensor;
};

int main() {
  Sensor *p = new Adapter(new FahrenheitSensor);
  std::cout << "Celsius temperature = " << p->getTemperature() << std::endl;
  delete p;
  return 0;
}