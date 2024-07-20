#include "IR.h"

// Constructor to initialize the IR sensor pin
IR::IR(int pin) {
    this->pin = pin;
}

// Initialize the IR sensor pin as input
void IR::init() {
    pinMode(pin, INPUT);
}

// Read the value from the IR sensor
int IR::read() {
    //Serial.print("Sensor is reading with pin number ");
    //Serial.println(pin);
    return digitalRead(pin);
}
