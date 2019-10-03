#ifndef SHIP_H
#define SHIP_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "location.h"

using namespace std;

class Ship {

public:
	enum ShipType {BATTLESHIP, CARRIER, CRUISER, DESTROYER, SUBMARINE};
	
	bool containsLoc(int loc);
	int getColBegin() { return mColBegin; }
	int getColEnd() { return mColEnd; }
	int getHitCount() { return mHitCount; }
	char getRowBegin() { return mRowBegin; }
	char getRowEnd() { return mRowEnd; }
	char getType();

	void addLoc(int i);
	void printSinkingReport(bool player);
	void reduceHitCount() { mHitCount--; }
	void setInfo(char row, int col, char orient);
	void setActive(bool active) { mActive = active; }

	virtual void setHitCount() = 0; // creates simple abstraction for possible future ship types
	string mType_s; // string for printout of sinking action

protected:
	bool mActive;
	int mHitCount;  // number of hits a ship can take before sinking
	int mColBegin;  // beginning column
	int mColEnd;    // ending column if placed horizontally otherwise same as begin
	vector<int> mLocations;
	char mRowBegin; // beginning row
	char mRowEnd;   // ending row if placed vertically otherwise same as begin  
	ShipType mType; // enum for type checking	        
};

#endif
