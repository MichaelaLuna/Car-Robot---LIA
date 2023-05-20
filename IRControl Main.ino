/*--------------------------------------------------------------------------------- Main Area ----------------------------------------------------------------------------------------*/

#include "IrControl.h"  // Include the "IrControl.h" header file
#include <Arduino.h>    // Include the "Arduino.h" header file

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define receiverPin 9     // Define receiverPins to this pin#

IrControl Ir (receiverPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);  // Initialize the object with the corresponding pin numbers

void setup() {          // Run the code once
  Ir.init();            // Initialization Method
}

void loop() {           // Run the code in loop
  Ir.ActionIR();        // Action Method
}
