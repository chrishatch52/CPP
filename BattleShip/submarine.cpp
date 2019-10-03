#include "submarine.h"

Submarine::Submarine(char row, int col, char orient)
{
    mType = SUBMARINE;
    setHitCount();
    setActive(true);
    setInfo(row,col,orient);
    mType_s = "Submarine";
}

Submarine::~Submarine()
{
    //do nothing, no memory allocated
}
