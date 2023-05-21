
/*----------------------------------------------------------------------- Header file for Obstacle Avoid ---------------------------------------------------------------------------*/

#ifndef OBSTACLEAVOID_H     // If not defined
#define OBSTACLEAVOID_H     // Define the library

#include <Servo.h>          // Include the "Servo.h" library
#include <Arduino.h>        // Include the "Arduino.h" library

class ObstacleAvoid {

private:                    // Encapsulation

  Servo myservo;            // Servo object for controlling the servo motor
  int echoPin;              // Pin number for the echo pin of the ultrasonic sensor
  int trigPin;              // Pin number for the trigger pin of the ultrasonic sensor
  int middleD;              // Distance measurement in the middle direction
  int rightD;               // Distance measurement in the right direction
  int leftD;                // Distance measurement in the left direction
  int motorA;               // Pin number for controlling motor A
  int motorB;               // Pin number for controlling motor B
  int motorSpeedA;          // Pin number for controlling motor speed of motor A
  int motorSpeedB;          // Pin number for controlling motor speed of motor B
  int enablePin;            // Pin number for enabling the motor driver

  void Forward();              // Method for moving forward
  void Stop();                 // Method for stopping
  void Backward();             // Method for going backward
  void Left();                 // Method for turning left
  void Right();                // Method for turning right
  int distanceComputation();   // Perform distance computation using the ultrasonic sensor

  public:
  ObstacleAvoid();                                                                                          // Default Constructor
  ObstacleAvoid(int pinEcho, int pinTrig, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable); // Function to set motor states and speeds
  
  void init();                                                                                              // Method for Initialization 
  void ActionObstacle();                                                                                    // Method for Action Obstacle

  
};        // End

#endif    // End of if not defined
