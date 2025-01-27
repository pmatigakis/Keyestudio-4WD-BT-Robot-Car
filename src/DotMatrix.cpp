#include "DotMatrix.h"

#include <Arduino.h>

void DotMatrix::iicStart() {
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(3);
  digitalWrite(sdaPin, HIGH);
  delayMicroseconds(3);
  digitalWrite(sdaPin, LOW);
  delayMicroseconds(3);
}

void DotMatrix::iicSend(unsigned char send_data) {
  for (char i = 0; i < 8; i++) {
    digitalWrite(sclPin, LOW);
    delayMicroseconds(3);
    if (send_data & 0x01) {
      digitalWrite(sdaPin, HIGH);
    } else {
      digitalWrite(sdaPin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(sclPin, HIGH);
    delayMicroseconds(3);
    send_data = send_data >> 1;
  }
}

void DotMatrix::iicEnd() {
  digitalWrite(sclPin, LOW);
  delayMicroseconds(3);
  digitalWrite(sdaPin, LOW);
  delayMicroseconds(3);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(3);
  digitalWrite(sdaPin, HIGH);
  delayMicroseconds(3);
}

DotMatrix::DotMatrix(uint8_t sclPin, uint8_t sdaPin) {
  this->sclPin = sclPin;
  this->sdaPin = sdaPin;
}

void DotMatrix::initialize() {
  pinMode(sclPin, OUTPUT);
  pinMode(sdaPin, OUTPUT);
}

void DotMatrix::display(unsigned char matrix_value[]) {
  iicStart();
  iicSend(0xc0);
  for (int i = 0; i < 16; i++) {
    iicSend(matrix_value[i]);
  }
  iicEnd();

  iicStart();
  iicSend(0x8A);
  iicEnd();
}
