#include "cruiser.h"

Cruiser::Cruiser(char row, int col, char orient)
{
    mType = CRUISER;
    setHitCount();
    setActive(true);
    setInfo(row,col,orient);
    mType_s = "Cruiser";
}

Cruiser::~Cruiser()
{
    //do nothing, no memory allocated
}
