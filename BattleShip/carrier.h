#ifndef CARRIER_H
#define CARRIER_H

#include "ship.h"

using namespace std;

class Carrier : public Ship
{

public:

    Carrier(char row, int col, char orient);
    ~Carrier();
    void setHitCount() { mHitCount = 5; }

};

#endif
