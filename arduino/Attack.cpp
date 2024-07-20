#include "Attack.h"

// Constructor to initialize with sumo movement object
Attack::Attack(SumoMovement &move) : sumo(move) {}

// Execute a push attack
void Attack::push() {
    sumo.setSpeed();
    sumo.moveForward();
}

// Placeholder for side flank attack logic
void Attack::sideFlank() {
    // Add logic for side flank attack
}

// Placeholder for back flank attack logic
void Attack::backFlank() {
    // Add logic for back flank attack
}

// Execute a ram attack
void Attack::ram() {
    sumo.setSpeed(255, 255, 255, 255);
    sumo.moveForward();
    delay(1000);
    sumo.moveBackward();
    delay(250);
}

// Placeholder for dodge logic
void Attack::dodge() {
    // Add logic for dodge
}

// Placeholder for lift logic
void Attack::lift() {
    // Add logic for lift
}
