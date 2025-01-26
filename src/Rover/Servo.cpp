#include "Servo.h"

#include <Arduino.h>
#include <stdint.h>

Servo::Servo(uint8_t pin) { this->pin = pin; }

void Servo::initialize() {
  pinMode(pin, OUTPUT);
  currentPosition = 0;
  setPosition(90);
}

void Servo::setPosition(uint8_t angle) {
  int pulse;
  pulse = map(angle, 0, 180, 500, 2500);

  if (currentPosition > angle) {
    for (int i = currentPosition; i >= angle; i--) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(pin, LOW);
      delayMicroseconds(20000 - pulse);
    }
  } else if (currentPosition < angle) {
    for (int i = currentPosition; i <= angle; i++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(pin, LOW);
      delayMicroseconds(20000 - pulse);
    }
  }

  currentPosition = angle;
}
