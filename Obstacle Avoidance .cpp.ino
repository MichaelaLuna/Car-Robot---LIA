
/*----------------------------------------------------------------------- .cpp file for Obstacle Avoid ---------------------------------------------------------------------------*/

#include "ObstacleAvoid.h"   // Include the "ObstacleAvoid.h" header file

// Constructor definition for the ObstacleAvoid class

ObstacleAvoid::ObstacleAvoid(int pinEcho, int pinTrig, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)
    : echoPin(pinEcho), trigPin(pinTrig), motorA(pinA), motorB(pinB),
      motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) {}


void ObstacleAvoid::init() {      // Method for initialization
  for (int i = 1; i < 9; i++) {   // Set pins 1 to 8 as OUTPUT
    pinMode(i, OUTPUT);   
  }
  pinMode(enablePin, OUTPUT);    // Set enablePin as OUTPUT
  myservo.attach(10);            // Attach servo to pin 10
  pinMode(echoPin, INPUT);       // Set echoPin as INPUT
  pinMode(trigPin, OUTPUT);      // Set trigPin as OUTPUT

  Stop();   // Stop the movement
  
}

int ObstacleAvoid::distanceComputation() {
  
  digitalWrite(trigPin, LOW);                           // Set trigPin LOW
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                          // Set trigPin HIGH
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                           // Set trigPin LOW
  float distanceMeasurement = pulseIn(echoPin, HIGH);   // Measure the pulse duration on echoPin
  distanceMeasurement = distanceMeasurement / 58;       // Convert the pulse duration to distance in cm
  return (int)distanceMeasurement;                      // Return the measured distance
}

void ObstacleAvoid::ActionObstacle() {
  myservo.write(90);                                    // Set servo angle to 90 degrees
  delay(300);
  middleD = distanceComputation();                      // Measure the distance

  if (middleD <= 15) {                                  // If this condition is met, then..
    Stop();                                             // Stop the movement
    delay(300);
    myservo.write(10);                                  // Set servo angle to 10 degrees
    delay(1000);

    rightD = distanceComputation();                     // Measure the distance on the right

    delay(300);
    myservo.write(90);                                  // Set servo angle to 90 degrees
    delay(1000);
    myservo.write(180);                                 // Set servo angle to 180 degrees
    delay(1000);

    leftD = distanceComputation();                      // Measure the distance on the left

    delay(300);
    myservo.write(90);                                  // Set servo angle to 90 degrees
    delay(1000);

    if (rightD > leftD) {                               // If this condition is met, then..
      Right();                                          // Turn right
      delay(350);
    } 
    else if (rightD < leftD) {                          // If this condition is met, then..
      Left();                                           // Turn left
      delay(350);
    }
    else if ((rightD <= 15) || (leftD <= 15)) {         // If this condition is met, then..
      Backward();                                       // Move backward
      delay(175);
    }
    else {                                              // If not then,
      Forward();                                        // Move forward
    }
  }
  else {                                                // If not then,
    Forward();                                          // Move forward
  }
}

void ObstacleAvoid::Forward() {
  digitalWrite(motorA, 1);        // Set motorA pin HIGH
  digitalWrite(motorB, 1);        // Set motorB pin HIGH
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

void ObstacleAvoid::Backward() {
  digitalWrite(motorA, 0);        // Set motorA pin LOW
  digitalWrite(motorB, 0);        // Set motorB pin LOW
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

void ObstacleAvoid::Left() {
  digitalWrite(motorA, 1);        // Set motorA pin HIGH
  digitalWrite(motorB, 0);        // Set motorB pin LOW
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

void ObstacleAvoid::Right() {
  digitalWrite(motorA, 0);        // Set motorA pin LOW to turn off
  digitalWrite(motorB, 1);        // Set motorB pin HIGH to turn on
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

void ObstacleAvoid::Stop() {
  digitalWrite(motorA, 1);         // Set motorA pin HIGH
  digitalWrite(motorB, 1);         // Set motorB pin HIGH
  analogWrite(motorSpeedA, 0);     // Set motorSpeedA to 0 
  analogWrite(motorSpeedB, 0);     // Set motorSpeedB to 0 
  digitalWrite(enablePin, HIGH);   // Set enablePin HIGH to enable the motors
}
