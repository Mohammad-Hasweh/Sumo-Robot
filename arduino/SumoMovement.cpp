#include "SumoMovement.h"

// Constructor to initialize motors
SumoMovement::SumoMovement(Motor &topLeft, Motor &topRight, Motor &bottomLeft, Motor &bottomRight) 
  : topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {
  tlSpeed = 128;
  blSpeed = 128;
  trSpeed = 128;
  brSpeed = 128;
}

// Set the speed for each motor
void SumoMovement::setSpeed(int tlSpeed, int blSpeed, int trSpeed, int brSpeed) {
    this->tlSpeed = tlSpeed;
    this->blSpeed = blSpeed;
    this->trSpeed = trSpeed;
    this->brSpeed = brSpeed;
}

// Stop all motors
void SumoMovement::stop() {
    topLeft.stop();
    topRight.stop();
    bottomLeft.stop();
    bottomRight.stop();
}

// Move the robot forward
void SumoMovement::moveForward() {
    topLeft.forward(tlSpeed);
    topRight.forward(trSpeed);
    bottomLeft.forward(blSpeed);
    bottomRight.forward(brSpeed);
}

// Move the robot backward
void SumoMovement::moveBackward() {
    topLeft.backward(tlSpeed);
    topRight.backward(trSpeed);
    bottomLeft.backward(blSpeed);
    bottomRight.backward(brSpeed);
}

// Move the robot left
void SumoMovement::moveLeft() {
    topLeft.backward(tlSpeed);
    topRight.forward(trSpeed);
    bottomLeft.forward(blSpeed);
    bottomRight.backward(brSpeed);
}

// Move the robot right
void SumoMovement::moveRight() {
    topLeft.forward(tlSpeed);
    topRight.backward(trSpeed);
    bottomLeft.backward(blSpeed);
    bottomRight.forward(brSpeed);
}

// Execute a back-right maneuver
void SumoMovement::backRight() {
    stop();
    setSpeed();
    moveBackward();
    delay(200);
    moveRight();
    delay(500);
}

// Execute a back-left maneuver
void SumoMovement::backLeft() {
    stop();
    moveBackward();
    delay(200);
    moveLeft();
    delay(500);
}

// Countermeasure for bottom-left edge detection
void SumoMovement::edgeBlCounter() {
    topRight.forward(255);
    topLeft.backward(255);
    bottomLeft.backward(255);
    bottomRight.backward(255);
    delay(500);
}

// Countermeasure for bottom-right edge detection
void SumoMovement::edgeBrCounter() {
    topRight.backward(255);
    topLeft.forward(255);
    bottomLeft.backward(255);
    bottomRight.backward(255);
    delay(500);
}
