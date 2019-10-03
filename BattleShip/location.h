#ifndef LOCATION_H
#define LOCATION_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Location {

    private:
    	int mCol;
	char mInfo; // character to print on board
    	char mRow;

    public:
        Location(char row, int col);
	~Location();

	int getCol() { return mCol; }
	char getInfo() { return mInfo; }	
	char getRow() { return mRow; }
	void setInfo(char info) { mInfo = info; }
};

#endif
