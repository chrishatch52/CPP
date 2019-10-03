// BattleShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include "location.h"
#include "game.h"
#include "board.h"

using namespace std;

int main()
{
	Game *game = new Game();
	string name;

	do {
		cout << "\n\nEnter your name: ";
		getline(cin, name);
		if (name.empty())
			cout << "Error Occurred -- Try Again" << endl;
	} while (name.empty());

	game->buildGame();
	game->playGame(name);

	return 0;
}//end main

