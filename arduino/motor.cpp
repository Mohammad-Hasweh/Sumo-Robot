#include "Motor.h"

// Constructor to initialize motor pins
Motor::Motor(int pinA, int pinB, int enable) {
    this->pinA = pinA;
    this->pinB = pinB;
    this->enable = enable;
}

// Initialize the motor pins as outputs
void Motor::init() {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(enable, OUTPUT);
}

// Move motor forward with given speed
void Motor::forward(int speed) {
    //Serial.print("Moving forward with speed of ");
    //Serial.println(speed);
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    analogWrite(enable, speed);  
}

// Move motor backward with given speed
void Motor::backward(int speed) {
    //Serial.print("Moving backward with speed of ");
    //Serial.println(speed);
    
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    analogWrite(enable, speed);  // No mapping, use speed directly
}

// Stop the motor
void Motor::stop() {
    //Serial.println("Stopping the motors");
    
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    analogWrite(enable, 0);
}
