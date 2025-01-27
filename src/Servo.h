#ifndef _SERVO_H_
#define _SERVO_H_

#include <stdint.h>

class Servo {
 public:
  Servo(uint8_t pin);
  void initialize();
  void setPosition(uint8_t angle);

 private:
  uint8_t pin;
  uint8_t currentPosition;
};

#endif
