
/* The Car Robot kit has its own ultrasonic sensor that acts as its eyes. It is a navigation tool that can measure 
   distances using sound waves. By creating this program, I managed to set it as the eye of my Car Robot that 
                         adjusted it to move without getting hit by any obstacle.
 

------------------------------------------------- This is the Class ----------------------------------------------------------- */


#include <Servo.h>          // Include the "Servo.h" library

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

public:
     
     ObstacleAvoid();                                                                                          // Default Constructor
     ObstacleAvoid(int pinEcho, int pinTrig, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)  // Constructor with pin assignments
     : echoPin(pinEcho), trigPin(pinTrig), motorA(pinA), motorB(pinB), 
     motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) {}
    
   void Forward() {
  digitalWrite(motorA, 1);        // Set motorA pin HIGH
  digitalWrite(motorB, 1);        // Set motorB pin HIGH
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

  void Backward() {
  digitalWrite(motorA, 0);        // Set motorA pin LOW
  digitalWrite(motorB, 0);        // Set motorB pin LOW
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

  void Left() {
  digitalWrite(motorA, 1);        // Set motorA pin HIGH
  digitalWrite(motorB, 0);        // Set motorB pin LOW
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

  void Right() {
  digitalWrite(motorA, 0);        // Set motorA pin LOW to turn off
  digitalWrite(motorB, 1);        // Set motorB pin HIGH to turn on
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
}

  void Stop() {
  digitalWrite(motorA, 1);         // Set motorA pin HIGH
  digitalWrite(motorB, 1);         // Set motorB pin HIGH
  analogWrite(motorSpeedA, 0);     // Set motorSpeedA to 0 
  analogWrite(motorSpeedB, 0);     // Set motorSpeedB to 0 
  digitalWrite(enablePin, HIGH);   // Set enablePin HIGH to enable the motors
}
    
  int distanceComputation() {
  
  digitalWrite(trigPin, LOW);                           // Set trigPin LOW
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                          // Set trigPin HIGH
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                           // Set trigPin LOW
  float distanceMeasurement = pulseIn(echoPin, HIGH);   // Measure the pulse duration on echoPin
  distanceMeasurement = distanceMeasurement / 58;       // Convert the pulse duration to distance in cm
  return (int)distanceMeasurement;                      // Return the measured distance
  
}
    
    void init() {                // Method for initialization
  for (int i = 1; i < 9; i++) {  // Set pins 1 to 8 as OUTPUT
    pinMode(i, OUTPUT);   
  }
  pinMode(enablePin, OUTPUT);    // Set enablePin as OUTPUT
  myservo.attach(10);            // Attach servo to pin 10
  pinMode(echoPin, INPUT);       // Set echoPin as INPUT
  pinMode(trigPin, OUTPUT);      // Set trigPin as OUTPUT

  Stop();                        // Stop the movement
  
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

};                                                      // End of class


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
