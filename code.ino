#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);  // (RX=10, TX=11)

// Left Motor    
const int L_PWM1 = 9;  
const int L_PWM2 = 6; 

// Right Motor   
const int R_PWM1 = 5;  
const int R_PWM2 = 2; 

// Cutter Motor 
const int CUTTER_EN = 11;  
const int CUTTER_IN1 = 12; 
const int CUTTER_IN2 = 13; 

void setup() {
    BT.begin(9600);  // Start Bluetooth communication

    // Motor Driver Pins
    pinMode(L_EN, OUTPUT);
    pinMode(L_PWM1, OUTPUT);
    pinMode(L_PWM2, OUTPUT);

    pinMode(R_EN, OUTPUT);
    pinMode(R_PWM1, OUTPUT);
    pinMode(R_PWM2, OUTPUT);

    // Cutter Motor Pins
    pinMode(CUTTER_EN, OUTPUT);
    pinMode(CUTTER_IN1, OUTPUT);
    pinMode(CUTTER_IN2, OUTPUT);

    // Ensure all motors are OFF at startup
    stopMotors();
    cutterStop();
}

void loop() {
    if (BT.available()) {
        char command = BT.read();  

        switch (command) {
            case 'F':  
                smoothMoveForward();
                break;
            case 'B':  
                smoothMoveBackward();
                break;
            case 'L':  
                smoothTurnLeft();
                break;
            case 'R':  
                smoothTurnRight();
                break;
            case 'S':  
                stopMotors();
                break;
            case 'X':  
                cutterForward();
                break;
            case 'Y':  
                cutterBackward();
                break;
            case 'Z':  
                cutterStop();
                break;
        }
    }
}

// **SMOOTH FORWARD MOVEMENT**
void smoothMoveForward() {
    for (int speed = 50; speed <= 180; speed += 10) {  
        analogWrite(L_PWM1, speed);  
        analogWrite(L_PWM2, 0);  

        analogWrite(R_PWM1, speed);  
        analogWrite(R_PWM2, 0);
        
        delay(20);  // Smooth acceleration
    }
}

// **SMOOTH BACKWARD MOVEMENT**
void smoothMoveBackward() {
    for (int speed = 50; speed <= 180; speed += 10) {  
        analogWrite(L_PWM1, 0);
        analogWrite(L_PWM2, speed);  

        analogWrite(R_PWM1, 0);
        analogWrite(R_PWM2, speed);
        
        delay(50);  
    }
}

// **SMOOTH LEFT TURN**
void smoothTurnLeft() {
    for (int speed = 50; speed <= 150; speed += 10) {  
        analogWrite(L_PWM1, 0);
        analogWrite(L_PWM2, 0);  

        analogWrite(R_PWM1, speed);
        analogWrite(R_PWM2, 0);
        
        delay(50);
    }
}

// **SMOOTH RIGHT TURN**
void smoothTurnRight() {
    for (int speed = 50; speed <= 150; speed += 10) {  
        analogWrite(L_PWM1, speed);
        analogWrite(L_PWM2, 0);  

        analogWrite(R_PWM1, 0);
        analogWrite(R_PWM2, 0);
        
        delay(50);
    }
}

// **SMOOTH STOP FUNCTION**
void stopMotors() { 
      analogWrite(L_PWM1, 0);
      analogWrite(L_PWM2, 0);
      analogWrite(R_PWM1, 0);
      analogWrite(R_PWM2, 0);
      delay(50);  
    

}

// **CUTTER CONTROL**
void cutterForward() {
    digitalWrite(CUTTER_IN1, HIGH);
    digitalWrite(CUTTER_IN2, LOW);
    analogWrite(CUTTER_EN, 170);
}

void cutterBackward() {
    digitalWrite(CUTTER_IN1, LOW);
    digitalWrite(CUTTER_IN2, HIGH);
    analogWrite(CUTTER_EN, 170);
}

void cutterStop() {
    digitalWrite(CUTTER_IN1, LOW);
    digitalWrite(CUTTER_IN2, LOW);
    analogWrite(CUTTER_EN, 0);
}
