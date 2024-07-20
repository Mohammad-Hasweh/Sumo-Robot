#ifndef EDGE_H
#define EDGE_H

#include "SumoMovement.h"
#include "IR.h"

class Edge {
public:
    Edge(SumoMovement &sumo, IR &topLeft, IR &topRight, IR &bottomLeft, IR &bottomRight);
    void detect();

private:
    SumoMovement &sumo;
    IR &topLeft;
    IR &topRight;
    IR &bottomLeft;
    IR &bottomRight;
};

#endif // EDGE_H
