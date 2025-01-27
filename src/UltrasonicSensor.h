#ifndef _ULTRASONIC_SENSOR_H_
#define _ULTRASONIC_SENSOR_H_

#include <stdint.h>

class UltrasonicSensor {
 public:
  UltrasonicSensor(uint8_t triggerPin, uint8_t echoPin);
  void initialize();
  float distance();

 private:
  uint8_t triggerPin;
  uint8_t echoPin;
};

#endif
