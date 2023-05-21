/*             The goal of this program is to make it possible for the ELEGOO Car Robot to play a socccer game. 
               The codes created in this made this all possible.
               The theme is knowing how to properly create a class and mix all of them together.
    

--------------------------------------------------------------------------------- Main Area ---------------------------------------------------------------*/


#include <IRremote.h>          // Include this header file
#include <Arduino.h>           // Include this header file
#include "Movement.h"          // Include this header file
#include "ObstacleAvoid.h"     // Include this header file
#include "LineFollower.h"      // Include this header file
#include "IrControl.h"         // Include this header file
#include "Soccer.h"            // Include this header file

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define echoPin 12        // Define echoPin to this pin#
#define trigPin 13        // Define trigPin to this pin#
#define readPin1 A0          // Define read1 to this pin#
#define readPin2 A1          // Define read2 to this pin#
#define readPin3 A2          // Define read3 to this pin#
#define receiverPin 9     // Define receiverPins to this pin#

IRrecv irrecv(9);         // This is connected to pin 9
decode_results results;   


Movement move (motorA, motorB, motorSpeedA, motorSpeedB, enablePin);                             // (7, 8, 5, 6, 3);
ObstacleAvoid obstacle(echoPin, trigPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);   // (12, 13, 7, 8, 5, 6, 3);
LineFollower line (readPin1, readPin2, readPin3, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);    // (A0, A1, A2, 7, 8, 5, 6, 3);
IrControl Ir (receiverPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);                 // (9, 7, 8, 5, 6, 3);
Soccer play (receiverPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin);                  // (9, 7, 8, 5, 6, 3);


void setup() { // Run the code once
  
  obstacle.init();  // Initialization for class "obstacle"
  Ir.init();        // Initialization for class "Ir"
  play.init();      // Initialization for class "play"
  
} // End of setup

void loop() { // Run the code in loop
  
  if (irrecv.decode(&results)) {      // Have we received an IR signal?
    
    switch(results.value) {          // If yes, go to cases:
      
      case 0xFF30CF:                 // Case 1: #1 button pressed, code of #1 button is FF30CF
           Ir.ActionIR();            // Call this
           break;                    // Tell Arduino to go on
                
      case 0xFF18E7:                 // Case 2: #2 button pressed, code of #2 button is FF18E7             
           line.ActionLineF();       // Call this
           break;                    // Tell Arduino to go on
           
      case 0xFF7A85:                 // Case 3: #3 button pressed, code of #3 button is FF7A85  
           move.ActionMove();        // Call this
           break;                    // Tell Arduino to go on
           
      case 0xFF10EF:                  // Case 4: #4 button pressed, code of #4 button is FF10EF
           obstacle.ActionObstacle(); // Call this
           break;                     // Tell Arduino to go on
           
      case 0xFF38C7:                  // Case 5: #5 button pressed, code of #5 button is FF38C7            
           play.ActionSoccer();       // Call this
           break;                     // Tell Arduino to go on
        
    }                                 // End of cases
    
    irrecv.resume();                  // Receive the next value
     
  }                                   // End of if    
}                                     // End of loop
