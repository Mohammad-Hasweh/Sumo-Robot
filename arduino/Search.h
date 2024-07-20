#ifndef SEARCH_H
#define SEARCH_H

#include "SumoMovement.h"

class Search {
public:
    Search(SumoMovement &move);
    
    void tornado();
    void zigzag();
    void randomWalk();
    void sShaped(); // No attackType parameter

private:
    SumoMovement &sumo;
};

#endif // SEARCH_H
