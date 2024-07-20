#ifndef SUMO_MOVEMENT_H
#define SUMO_MOVEMENT_H

#include "Motor.h"

class SumoMovement {
public:
    SumoMovement(Motor &topLeft, Motor &topRight, Motor &bottomLeft, Motor &bottomRight);
    
    void setSpeed(int tlSpeed = 128, int blSpeed = 128, int trSpeed = 128, int brSpeed = 128);
    void stop();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void backRight();
    void backLeft();
    void edgeBlCounter();
    void edgeBrCounter();

private:
    Motor &topLeft, &topRight, &bottomLeft, &bottomRight;
    int tlSpeed, blSpeed, trSpeed, brSpeed;
};

#endif // SUMO_MOVEMENT_H
