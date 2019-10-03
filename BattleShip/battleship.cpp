#include "battleship.h"


Battleship::Battleship(char row, int col, char orient)
{
    mType = BATTLESHIP;
    setHitCount();
    setActive(true);
    setInfo(row,col,orient);
    mType_s = "Battleship";
}

Battleship::~Battleship()
{
    //do nothing, no memory allocated
}
