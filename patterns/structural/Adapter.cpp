#include <iostream>

class FahrenheitSensor // Existing class
{
  float t = 132.0;
public:
  float getFahrenheitTemp() {
    // Some functionality
    return t;
  }
protected:
  void adjust() {
    t += 0.1;
  }
};

class Sensor {
public:
  virtual ~Sensor() = default;
  virtual float getTemperature() = 0;
  virtual void adjust() = 0;
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
  void adjust() override {} // can't use protected one
private:
  FahrenheitSensor *p_fsensor;
};

class InhAdapter : public Sensor, private FahrenheitSensor {
public:
  InhAdapter() = default;
  float getTemperature() override {
    return static_cast<float>((getFahrenheitTemp() - 32.0) * 5.0 / 9.0);
  }
  void adjust() override {
    FahrenheitSensor::adjust();
  }
};

int main() {
  Sensor *p = new Adapter(new FahrenheitSensor);
  Sensor *ip = new InhAdapter();
  ip->adjust();
  std::cout << "T = " << p->getTemperature() << std::endl;
  std::cout << "T = " << ip->getTemperature() << std::endl;
  delete p;
  return 0;
}