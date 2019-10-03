#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "ship.h"

using namespace std;

class Battleship : public Ship
{

public:
    
    Battleship(char row, int col, char orient);
    ~Battleship();
    void setHitCount() { mHitCount = 4; }

};
#endif
