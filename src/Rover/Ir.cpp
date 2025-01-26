#include <Arduino.h>
#include <stdint.h>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>

#include "Ir.h"

IR::IR(uint8_t pin) { this->pin = pin; }

void IR::initialize() { IrReceiver.begin(pin, ENABLE_LED_FEEDBACK); }

int16_t IR::read() {
  uint16_t command;
  if (IrReceiver.decode()) {
    command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    return command;
  }

  return -1;
}
