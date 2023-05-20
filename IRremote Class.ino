/*                  The Car Robot from ELEGOO kit has its own remote on the kit already programmed by the
                    creators of it. By this program I created, I was able to use the Infrared remote to control
                    the Car Robot using specifically the buttons that I want and made these respond the way I 
                    programmed it to. 



                                             /*------------- This is the Class -----------------*/ 


#include <IRremote.h> // Include the library for the IRremote

class IrControl {
  private:
    int receiver;
    int MotorA;
    int MotorB;
    int Motor_SpeedA;
    int Motor_SpeedB;
    int EnablePin;
    IRrecv irrecv;
    decode_results results;

  public:
    IrControl(){} // Default Constructor
    IrControl(int receiverPin, int motorAPin, int motorBPin, int motorSpeedAPin, int motorSpeedBPin, int enablePin)
      : receiver(receiverPin), MotorA(motorAPin), MotorB(motorBPin), Motor_SpeedA(motorSpeedAPin),
        Motor_SpeedB(motorSpeedBPin), EnablePin(enablePin), irrecv(receiver), results() {}

    void init() {
      irrecv.enableIRIn();

      for (int i = 1; i < 9; i++) {
        pinMode(i, OUTPUT);
      }
      pinMode(EnablePin, OUTPUT);
    }

    void run() {
      digitalWrite(EnablePin, HIGH);

      if (irrecv.decode(&results)) {
        switch (results.value) {
          case 0xFF629D:
            Forward();
            break;
          case 0xFFA857:
            Backward();
            break;
          case 0xFFC23D:
            Right();
            delay(1000);
            Forward();
            break;
          case 0xFF22DD:
            Left();
            delay(1000);
            Forward();
            break;
          case 0xFF02FD:
            Stop();
            break;
        }

        irrecv.resume();
      }
    }

    void Forward() {
      digitalWrite(MotorA, HIGH);
      digitalWrite(MotorB, HIGH);
      analogWrite(Motor_SpeedA, 100);
      analogWrite(Motor_SpeedB, 100);
    }

    void Backward() {
      digitalWrite(MotorA, LOW);
      digitalWrite(MotorB, LOW);
      analogWrite(Motor_SpeedA, 100);
      analogWrite(Motor_SpeedB, 100);
    }

    void Left() {
      digitalWrite(MotorA, HIGH);
      digitalWrite(MotorB, LOW);
      analogWrite(Motor_SpeedA, 100);
      analogWrite(Motor_SpeedB, 100);
    }

    void Right() {
      digitalWrite(MotorA, LOW);
      digitalWrite(MotorB, HIGH);
      analogWrite(Motor_SpeedA, 100);
      analogWrite(Motor_SpeedB, 100);
    }

    void Stop() {
      digitalWrite(MotorA, LOW);
      digitalWrite(MotorB, LOW);
      analogWrite(Motor_SpeedA, 0);
      analogWrite(Motor_SpeedB, 0);
    }
};

// Initialize the robot object with the corresponding pin numbers
IrControl myIrControl(9, 7, 8, 5, 6, 3);

void setup() {
  myIrControl.init();
}

void loop() {
  myIrControl.run();
}
