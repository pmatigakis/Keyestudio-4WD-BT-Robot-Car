#include "UltrasonicSensor.h"

#include <Arduino.h>
#include <stdint.h>

UltrasonicSensor::UltrasonicSensor(uint8_t triggerPin, uint8_t echoPin) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}

void UltrasonicSensor::initialize() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::distance() {
  long duration;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH, 5000);
  if (duration == 0) {
    return -1;
  }

  return (duration / 2) / 29.1;
}
