#include "location.h"


Location::Location(char row, int col)  // default object
{
    mRow = row;
    mCol = col;
    mInfo = '*';
}

Location::~Location()
{
    //do nothing, no memory allocated
}
