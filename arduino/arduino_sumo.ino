#include <Arduino.h>
#include "Motor.h"
#include "IR.h"
#include "SumoMovement.h"
#include "Attack.h"
#include "Search.h"
#include "Oponnent.h"
#include "Edge.h"

// Define motor pins
const int pinA1 = 3;
const int pinB1 = 4;
const int enable1 = 5;

const int pinA2 = 6;
const int pinB2 = 7;
const int enable2 = 8;

const int pinA3 = 9;
const int pinB3 = 10;
const int enable3 = 11;

const int pinA4 = 12;
const int pinB4 = 13;
const int enable4 = 14;

// Define IR sensor pins
const int frontLeftPin = A0;
const int frontBetweenPin = A1;
const int frontRightPin = A2;
const int leftPin = A3;
const int rightPin = A4;
const int backPin = A5;

// Define edge sensor pins
const int edgeTopLeftPin = A6;
const int edgeTopRightPin = A7;
const int edgeBottomLeftPin = A8;
const int edgeBottomRightPin = A9;

// Initialize motors
Motor motorTopLeft(pinA1, pinB1, enable1);
Motor motorTopRight(pinA2, pinB2, enable2);
Motor motorBottomLeft(pinA3, pinB3, enable3);
Motor motorBottomRight(pinA4, pinB4, enable4);

// Initialize IR sensors
IR irFrontLeft(frontLeftPin);
IR irFrontBetween(frontBetweenPin);
IR irFrontRight(frontRightPin);
IR irLeft(leftPin);
IR irRight(rightPin);
IR irBack(backPin);

// Initialize edge sensors
IR edgeTopLeft(edgeTopLeftPin);
IR edgeTopRight(edgeTopRightPin);
IR edgeBottomLeft(edgeBottomLeftPin);
IR edgeBottomRight(edgeBottomRightPin);

// Initialize movement, attack, search, opponent, and edge detection
SumoMovement sumo(motorTopLeft, motorTopRight, motorBottomLeft, motorBottomRight);
Attack attack(sumo);
Search search(sumo);
Oponnent opponent(sumo, irFrontLeft, irFrontBetween, irFrontRight, irLeft, irRight, irBack, attack);
Edge edge(sumo, edgeTopLeft, edgeTopRight, edgeBottomLeft, edgeBottomRight);

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Initialize motors and sensors
    motorTopLeft.init();
    motorTopRight.init();
    motorBottomLeft.init();
    motorBottomRight.init();

    irFrontLeft.init();
    irFrontBetween.init();
    irFrontRight.init();
    irLeft.init();
    irRight.init();
    irBack.init();

    edgeTopLeft.init();
    edgeTopRight.init();
    edgeBottomLeft.init();
    edgeBottomRight.init();
}

void loop() {
    // Detect edges and handle countermeasures
    edge.detect();

    // Track the opponent and perform an attack
    opponent.track(&Attack::push, 2000);  // Track for up to 2000 milliseconds and use the push attack

    // Example of searching behavior
    search.randomWalk();  // Move in random directions

    // Optional: Add additional behaviors or logic here
    delay(1000);  // Delay to avoid rapid execution
}
