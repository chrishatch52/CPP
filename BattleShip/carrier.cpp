#include "carrier.h"


Carrier::Carrier(char row, int col, char orient)
{
    mType = CARRIER;
    setHitCount();
    setActive(true);
    setInfo(row,col,orient);
    mType_s = "Carrier";
}

Carrier::~Carrier()
{
    //do nothing, no memory allocated 
}

