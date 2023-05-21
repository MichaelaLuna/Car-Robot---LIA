
/*------------------------------------------------------------------------------- Main Area ---------------------------------------------------------------------------*/


#include <Arduino.h>
#include "ObstacleAvoid.h"

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define echoPin 12        // Define echoPin to this pin#
#define trigPin 13        // Define trigPin to this pin#


ObstacleAvoid obstacle(echoPin, trigPin, motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {
  obstacle.init();           // Initialization for class "obstacle"
}

void loop() {
  obstacle.ActionObstacle(); // Call the action method
}
