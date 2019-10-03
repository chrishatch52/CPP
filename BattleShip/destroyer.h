#ifndef DESTROYER_H
#define DESTROYER_H

#include "ship.h"

class Destroyer : public Ship
{

public:
    Destroyer(char row, int col, char orient);
    ~Destroyer();
    void setHitCount() { mHitCount = 3; }
};

#endif
