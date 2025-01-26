#include "LineTracking.h"

#include <Arduino.h>

LineTrackingSensor::LineTrackingSensor(uint8_t left_pin, uint8_t center_pin,
                                       uint8_t right_pin) {
  _left_pin = left_pin;
  _center_pin = center_pin;
  _right_pin = right_pin;
}

void LineTrackingSensor::initialize() {
  pinMode(_left_pin, INPUT);
  pinMode(_center_pin, INPUT);
  pinMode(_right_pin, INPUT);
}

uint8_t LineTrackingSensor::read() {
  uint8_t left = digitalRead(_left_pin);
  uint8_t center = digitalRead(_center_pin);
  uint8_t right = digitalRead(_right_pin);

  return (left << 2) | (center << 1) | right;
}
