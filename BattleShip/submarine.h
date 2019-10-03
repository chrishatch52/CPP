#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "ship.h"

class Submarine : public Ship
{

public:
    Submarine(char row, int col, char orient);
    ~Submarine();
    void setHitCount() { mHitCount = 3; }
};

#endif
