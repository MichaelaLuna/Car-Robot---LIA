
/*------------------------------------------------------------------------------- Main Area ---------------------------------------------------------------------------*/

#include <Arduino.h>        // Include Arduino library
#include "LineFollower.h"   // Include this header file

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define readPin1 A0       // Define read1 to this pin#
#define readPin2 A1       // Define read2 to this pin#
#define readPin3 A2       // Define read3 to this pin#

LineFollower line (readPin1, readPin2, readPin3, motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {            // Run the code once
  line.init();               // Method for Initialization
}

void loop() {             // Run the code in loop
  line.ActionLineF();     // Run action
}
  
