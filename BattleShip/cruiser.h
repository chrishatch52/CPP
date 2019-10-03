#ifndef CRUISER_H
#define CRUISER_H

#include "ship.h"

using namespace std;

class Cruiser : public Ship
{

public:
    Cruiser(char row, int col, char orient);
    ~Cruiser();
    void setHitCount() { mHitCount = 2; }

};

#endif
