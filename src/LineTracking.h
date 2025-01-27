#ifndef _LINE_TRACKING_H_
#define _LINE_TRACKING_H_

#include <stdint.h>

class LineTrackingSensor {
 public:
  LineTrackingSensor(uint8_t left_pin, uint8_t center_pin, uint8_t right_pin);
  void initialize();
  uint8_t read();

 private:
  uint8_t _left_pin;
  uint8_t _center_pin;
  uint8_t _right_pin;
};

#endif
