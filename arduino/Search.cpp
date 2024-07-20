#include "Search.h"

// Constructor
Search::Search(SumoMovement &move) : sumo(move) {}

// Move in a circular pattern
void Search::tornado() {
    sumo.setSpeed(50, 50, 50, 50);
    sumo.moveRight();
}

// Move in a zigzag pattern
void Search::zigzag() {
    sumo.setSpeed(100, 100, 100, 100);
    sumo.moveForward();
    // Additional zigzag logic here
}

// Move in random directions
void Search::randomWalk() {
    unsigned long delayTime = 500; // 500 milliseconds
    int randValue = random(1, 4); // Random number between 1 and 3

    if (randValue == 1) {
        sumo.moveForward();
    } else if (randValue == 2) {
        sumo.moveLeft();
    } else {
        sumo.moveRight();
    }

    delay(delayTime);
}

// Move in an S-shaped pattern
void Search::sShaped() {
    sumo.setSpeed(100, 100, 100, 100);
    
    // Example logic for the S-shaped movement
    sumo.moveForward();
    delay(500);  // Move forward for a short time
    sumo.moveLeft();
    delay(500);  // Turn left for a short time
    sumo.moveForward();
    delay(500);  // Move forward again
    sumo.moveRight();
    delay(500);  // Turn right to adjust direction
    
    // Add additional logic for S-shaped movement as needed
}
