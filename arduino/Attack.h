#ifndef ATTACK_H
#define ATTACK_H

#include "SumoMovement.h"

class Attack {
public:
    Attack(SumoMovement &move);
    
    void push();
    void sideFlank();
    void backFlank();
    void ram();
    void dodge();
    void lift();

private:
    SumoMovement &sumo;
};

#endif // ATTACK_H
