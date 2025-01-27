#include <Arduino.h>
#define DECODE_NEC
#include <IRremote.hpp>
#include <Rover.h>
#include <stdint.h>

#define MoveSpeed 200
#define TurnSpeed 200
#define MOVE_FORWARD 0x46
#define MOVE_BACKWARDS 0x15
#define TURN_LEFT 0x44
#define TURN_RIGHT 0x43
#define STOP 0x40

Rover rover;
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
int16_t command;

void setup() {
  rover.initialize();
  rover.display(smile);
}

void loop() {
  command = rover.readIR();
  if (command != -1) {
    switch (command) {
        case MOVE_BACKWARDS:
          rover.move(-MoveSpeed, -MoveSpeed);
          break;
        case MOVE_FORWARD:
          rover.move(MoveSpeed, MoveSpeed);
          break;
        case TURN_LEFT:
          rover.move(-TurnSpeed, TurnSpeed);
          break;
        case TURN_RIGHT:
          rover.move(TurnSpeed, -TurnSpeed);
          break;
        case STOP:
          rover.move(0, 0);
          break;
      }
  }
}
