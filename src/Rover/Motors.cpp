#include "Motors.h"

#include <Arduino.h>
#include <stdint.h>

Motors::Motors(uint8_t ctrlPin, uint8_t pwmPin) {
  this->ctrlPin = ctrlPin;
  this->pwmPin = pwmPin;
}

void Motors::initialize() {
  pinMode(ctrlPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  direction = FORWARD;
  digitalWrite(ctrlPin, HIGH);
}

void Motors::move(short speed) {
  if (speed > 0 && direction != FORWARD) {
    direction = FORWARD;
    digitalWrite(ctrlPin, HIGH);
  } else if (speed < 0 && direction != REVERSE) {
    direction = REVERSE;
    digitalWrite(ctrlPin, LOW);
  }

  speed = abs(speed);
  speed = speed > MAX_SPEED ? MAX_SPEED : speed;

  analogWrite(pwmPin, speed);
}
