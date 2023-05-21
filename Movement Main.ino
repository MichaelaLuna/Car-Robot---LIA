
/*------------------------------------------------------------------------------- Main Area ---------------------------------------------------------------------------*/

#include <Arduino.h>       // Include Arduino library
#include "Movement.h"     // Include this header file

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#

Movement move(motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {            // Run the code once
}                         // End of setup

void loop() {             // Run the code in loop
  move.ActionMove();      // Run the action
}                         // End of loop
