#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "location.h"

#define horizLength 30

using namespace std;

class Board {

    private:
	void printFooter();
	void printHeader(string name);
	void printNums();

    public:
    	Board();
	~Board();
	void printBoard(string name, vector<Location> locations_p, vector<Location> locations_c);
};

#endif
