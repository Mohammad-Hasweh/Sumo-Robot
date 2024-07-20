#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int pinA, int pinB, int enable);
    
    void init();
    void forward(int speed = 255);
    void backward(int speed = 255);
    void stop();

private:
    int pinA, pinB, enable;
};

#endif // MOTOR_H
