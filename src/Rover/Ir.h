#ifndef _IR_H_
#define _IR_H_

#include <Arduino.h>
#include <stdint.h>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>

class IR {
 public:
  IR(uint8_t pin);
  void initialize();
  int16_t read();

 private:
  uint8_t pin;
};

#endif
