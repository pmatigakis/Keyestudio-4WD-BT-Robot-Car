# Keyestudio 4WD BT robot car Arduino library

This is a library that allows to control the Keyestudio 4WD BT robot car using arduino.

## Installation

Download this repository as a zip file and install it using the `Sketch->Include library-> Add .ZIP library` menu in the arduino IDE.

## Usage

Import the `Rover.h` header in your project and use the `Rover` class to control the robot car.
If you plan to use the IR controller, we need to initialize it using the `IRremote` library.

```c++
#include <Arduino.h>
#define DECODE_NEC
#include <IRremote.hpp>
#include <Rover.h>
#include <stdint.h>

#define MoveSpeed 200

Rover rover;

void setup() {
  rover.initialize();
}

void loop() {
    rover.move(MoveSpeed, MoveSpeed);
}

```

## Examples

See the `examples` folder for some example sketches.

control.ino: This sketch show  how to control the robot car using the IR controller.
