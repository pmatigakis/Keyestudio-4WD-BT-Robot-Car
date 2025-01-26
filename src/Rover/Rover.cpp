#include "Rover.h"

#include <stdint.h>

#include "DotMatrix.h"
#include "Ir.h"
#include "LineTracking.h"
#include "Motors.h"
#include "Pins.h"
#include "Servo.h"
#include "UltrasonicSensor.h"

Rover::Rover() {
  servo = new Servo(SERVO_PIN);
  ultrasonicSensor = new UltrasonicSensor(ULTRASONIC_SENSOR_TRIG_PIN,
                                          ULTRASONIC_SENSOR_ECHO_PIN);
  leftMotors = new Motors(ML_CTRL, ML_PWM);
  rightMotors = new Motors(MR_CTRL, MR_PWM);
  dotMatrix = new DotMatrix(DOT_MATRIX_SCL_PIN, DOT_MATRIX_SDA_PIN);
  ir = new IR(IR_RECV_PIN);
  lineTrackingSensor = new LineTrackingSensor(LEFT_LINE_TRACKING_SENSOR_PIN,
                                              CENTER_LINE_TRACKING_SENSOR_PIN,
                                              RIGHT_LINE_TRACKING_SENSOR_PIN);
}

void Rover::initialize() {
  ultrasonicSensor->initialize();
  servo->initialize();
  leftMotors->initialize();
  rightMotors->initialize();
  dotMatrix->initialize();
  ir->initialize();
  lineTrackingSensor->initialize();
}

void Rover::move(short leftMotorsSpeed, short rightMotorsSpeed) {
  leftMotors->move(leftMotorsSpeed);
  rightMotors->move(rightMotorsSpeed);
}

float Rover::readUltrasonicSensorValue() {
  return ultrasonicSensor->distance();
}

void Rover::setUltrasonicSensorPosition(uint8_t angle) {
  servo->setPosition(angle);
}

void Rover::display(unsigned char matrix_value[]) {
  dotMatrix->display(matrix_value);
}

int16_t Rover::readIR() { return ir->read(); }

uint8_t Rover::readLineTrackingSensor() { return lineTrackingSensor->read(); }
