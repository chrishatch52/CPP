#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "location.h"
#include "board.h"
#include "ship.h"
#include "battleship.h"
#include "carrier.h"
#include "cruiser.h"
#include "destroyer.h"
#include "submarine.h"

#define MAX 10

using namespace std;

class Game {

    private:
    	vector<Location> mPlayerLocations; // players hits (X), misses (0), Ships by type {Battleship(B),Carrier(C),Cruiser(U),Destroyer(D),Submarine(S)}, Empty/Unknown(*)
	vector<Location> mCompLocations;  // computers hits (X), misses (0), Ships by type {Battleship(B),Carrier(C),Cruiser(U),Destroyer(D),Submarine(S)}, Empty/Unknown(*)
	vector<Ship*> mPlayerShips;  // players remaining ships
	vector<Ship*> mComputerShips;  // computers remaining ships
	string mName;  // players name
	Board* mBoard;
	bool mPlayer;
	int mPlayerShipCount;
	int mComputerShipCount;

	void addShips(bool player, Ship* ship);
	string attackResult(bool player, char row, int col);
        Ship *buildShip(char row, int col, char orient, Ship::ShipType type); // factory
	void fillLocations(); // fill both location vectors with default locations to be modified
	bool removeShips();   // check for sunk ships, if found, print who sank which type
	void setLocations();  // modify location character with ship if present
	void setComputerShips(); // add seven ships to computer board statically
	void setHorizontal(bool player, Ship* tmp, int start, int end);
	void setVertical(bool player, Ship* tmp, int start, int end);


    public:
	Game();
	~Game();

    	void buildGame();           // allow for player to select locations of ships, set locations of computer ships
        void playGame(string name);
};

#endif
