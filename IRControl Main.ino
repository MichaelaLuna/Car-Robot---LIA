/*--------------------------------------------------------------------------------- Main Area ----------------------------------------------------------------------------------------*/

#include "IrControl.h"  // Include the "IrControl.h" header file
#include <Arduino.h>    // Include the "Arduino.h" header file

IrControl Ir (receiverPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);  // Initialize the object with the corresponding pin numbers

void setup() {          // Run the code once
  Ir.init();            // Initialization Method
}

void loop() {           // Run the code in loop
  Ir.ActionIR();        // Action Method
}
