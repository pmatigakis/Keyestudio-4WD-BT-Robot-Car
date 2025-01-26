#ifndef _MOTORS_H_
#define _MOTORS_H_

#include <stdint.h>

#define MAX_SPEED 250

enum Direction { FORWARD, REVERSE };

class Motors {
 public:
  Motors(uint8_t ctrlPin, uint8_t pwmPin);
  void initialize();
  void move(short speed);

 private:
  uint8_t ctrlPin;
  uint8_t pwmPin;
  Direction direction;
};

#endif
