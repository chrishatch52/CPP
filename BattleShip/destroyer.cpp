#include "destroyer.h"

Destroyer::Destroyer(char row, int col, char orient)
{
    mType = DESTROYER;
    setHitCount();
    setActive(true);
    setInfo(row,col,orient);
    mType_s = "Destroyer";
}

Destroyer::~Destroyer()
{
    //do nothing, no memory allocated
}
