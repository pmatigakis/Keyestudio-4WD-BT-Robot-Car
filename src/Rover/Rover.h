#ifndef _ROVER_H_
#define _ROVER_H_

#include <stdint.h>

#include "DotMatrix.h"
#include "Ir.h"
#include "LineTracking.h"
#include "Motors.h"
#include "Servo.h"
#include "UltrasonicSensor.h"

class Rover {
 public:
  Rover();
  void initialize();
  void move(short leftMotorsSpeed, short rightMotorsSpeed);
  float readUltrasonicSensorValue();
  void setUltrasonicSensorPosition(uint8_t angle);
  void display(unsigned char matrix_value[]);
  int16_t readIR();
  uint8_t readLineTrackingSensor();

 private:
  Servo *servo;
  UltrasonicSensor *ultrasonicSensor;
  Motors *leftMotors;
  Motors *rightMotors;
  DotMatrix *dotMatrix;
  IR *ir;
  LineTrackingSensor *lineTrackingSensor;
};

#endif
