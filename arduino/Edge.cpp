#include "Edge.h"

// Constructor to initialize with sumo movement and edge sensors
Edge::Edge(SumoMovement &sumo, IR &topLeft, IR &topRight, IR &bottomLeft, IR &bottomRight)
    : sumo(sumo), topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {}

// Detect edge and take appropriate action
void Edge::detect() {
    bool topLeftEdge = topLeft.read();
    bool topRightEdge = topRight.read();
    bool bottomLeftEdge = bottomLeft.read();
    bool bottomRightEdge = bottomRight.read();

    if (bottomLeftEdge) {
        sumo.edgeBlCounter();
    }
    if (bottomRightEdge) {
        sumo.edgeBrCounter();
    }
}
