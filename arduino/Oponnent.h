#ifndef OPONNENT_H
#define OPONNENT_H

#include "SumoMovement.h"
#include "IR.h"
#include "Attack.h"

class Oponnent {
public:
    Oponnent(SumoMovement &sumo, IR &frontLeft, IR &frontBetween, IR &frontRight, IR &left, IR &right, IR &back, Attack &attackObj);
    void track(void (Attack::*attackType)(), unsigned long detectionTimeout = 200);

private:
    SumoMovement &sumo;
    IR &frontLeft;
    IR &frontBetween;
    IR &frontRight;
    IR &left;
    IR &right;
    IR &back;
    Attack &attackObj; // Add Attack reference
};

#endif // OPONNENT_H
