#include "Oponnent.h"

// Constructor to initialize with sumo movement, IR sensors, and Attack
Oponnent::Oponnent(SumoMovement &sumo, IR &frontLeft, IR &frontBetween, IR &frontRight, IR &left, IR &right, IR &back, Attack &attackObj)
    : sumo(sumo), frontLeft(frontLeft), frontBetween(frontBetween), frontRight(frontRight), left(left), right(right), back(back), attackObj(attackObj) {}

// Track opponent and execute the specified attack type
void Oponnent::track(void (Attack::*attackType)(), unsigned long detectionTimeout) {
    unsigned long startTime = millis();
    bool flag = false;

    while (true) {
        bool FC = frontBetween.read();
        bool FR = frontRight.read();
        bool FL = frontLeft.read();
        bool L = left.read();
        bool R = right.read();
        bool B = back.read();

        // Check if any sensor detects something
        if (FC || FR || FL || L || R || B) {
            startTime = millis();  // Reset the timer
            flag = true;

            // Call the attack type function when something is detected
            (attackObj.*attackType)();  // Call the member function pointer
        } 
        // Exit the loop if the timeout period has passed or if a flag was set
        else if (millis() - startTime > detectionTimeout || flag) {
            break;
        }

        // Perform actions based on sensor readings
        if (FC) {
            while (FC) {
                sumo.setSpeed(255, 255, 255, 255);
                sumo.moveForward();
                FC = frontBetween.read();  // Update the sensor value
            }
        } else if (FL || L) {
            sumo.moveLeft();
        } else if (FR || R) {
            sumo.moveRight();
        } else if (B) {
            sumo.moveBackward();
        }
        // Added break condition if none of the sensors are triggered
        else {
            break;
        }
    }
}
