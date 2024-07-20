#ifndef IR_H
#define IR_H

#include <Arduino.h>

class IR {
public:
    IR(int pin);
    void init();
    int read();

private:
    int pin;
};

#endif // IR_H
