
/*---------------------------------------------------------------------- Main Area -------------------------------------------------------------------*/


#include <Arduino.h>
#include "Soccer.h"

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define receiverPin 9     // Define receiverPins to this pin#

Soccer play (receiverPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {            // Run the code once
  play.init();            // Initialization for class "play"
}                         // end of setup

void loop() {             // Run the code in loop
  play.ActionSoccer();    // Call this action
}                         // End of loop
