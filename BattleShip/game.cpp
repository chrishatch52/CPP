#include "game.h"


Game::Game()  // instantiate game board
{
    mBoard = new Board();
    mPlayerShipCount = 7;
    mComputerShipCount = 7;
}

Game::~Game()
{ }

string Game::attackResult(bool player, char row, int col)
{
    int attackLoc = ((row-65)*10)+(col);
    char result = 'O';
    Ship* tmp;

    if(player)
    {
	for(int i = 0; i < (int)mComputerShips.size(); i++)
	{
	    tmp = mComputerShips[i];
	    if(tmp->containsLoc(attackLoc))
	    {
		result = 'X';
		tmp->reduceHitCount();
		if(tmp->getHitCount() == 0)
		{
		    tmp->setActive(false);
		    mPlayerShipCount--;
		}
	    }
	}
	mCompLocations[attackLoc].setInfo(result);
    }
    else
    {
	for(int i = 0; i < (int)mPlayerShips.size(); i++)
	{
	    tmp = mPlayerShips[i];
	    if(tmp->containsLoc(attackLoc))
	    {
		tmp->reduceHitCount();
		if(tmp->getHitCount() == 0)
		{
		    tmp->setActive(false);
		    mComputerShipCount--;
		}
		result = 'X';
	    }
	} 
	mPlayerLocations[attackLoc].setInfo(result);
    }

    return "";
}//end attackResult

void Game::buildGame() // fill both computer game board, and player defined game board sections
{
    char tmpRow;
    int tmpCol;
    char tmpOrient;

    cout << "Valid locations are [A-J][1-10]" << endl;
    cout << "\nEnter Location and Orientation for each ship (Ex. A 2 H)" << endl;

    cout << "\nBattleship:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::BATTLESHIP));

    cout << "\nCarrier:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::CARRIER));

    cout << "\nCruiser #1:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::CRUISER));

    cout << "\nCruiser #2:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::CRUISER));

    cout << "\nDestroyer #1:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::DESTROYER));

    cout << "\nDestroyer #2:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::DESTROYER));

    cout << "\nSubmarine:\n\n";
    cin >> tmpRow >> tmpCol >> tmpOrient;
    addShips(true, buildShip(tmpRow, tmpCol, tmpOrient, Ship::SUBMARINE));

    setComputerShips();
    fillLocations();
    setLocations();
    
}//end buildGame

void Game::playGame(string name)
{
    bool exit = false, playerActive = true, gameOver = false;
    string tmpLoc;
    string compResult, playerResult;
    char tmpRow;
    int tmpCol;
    char rowChars[] = {'A','B','C','D','E','F','G','H','I','J'};

    do
    {
	    mBoard->printBoard(name, mPlayerLocations, mCompLocations);
            if(playerActive)
	    {
		cout << "Enter a space to attack(Ex. A1 -- x to quit): ";
		cin >> tmpLoc;
		if(tmpLoc.compare("x")==0)
		{
		    exit = true;
		    break;
		}
		else
		{
		    tmpRow = tmpLoc[0];
		    tmpCol = atoi(tmpLoc.substr(1, tmpLoc.length()).c_str());
		    playerResult = attackResult(true, tmpRow, tmpCol-1);
		    playerActive = !playerActive; // flip active player
		}
	    }
	    else
	    {
		srand(time(NULL)); // seed random with time 0
		int randRow;
		int randCol;
		
		do
		{
		    randRow = rand() % 9; // generate random between 1-10 (A-I)
		    randCol = rand() % 9; // generate random between 1-10
		    
		    compResult = attackResult(false, rowChars[randRow], randCol);
		
		}while(compResult.compare("")!=0);
		playerActive = !playerActive; // flip active player
	    }
	    
	    gameOver = removeShips();
    }while(!exit || gameOver);
}//end playGame

void Game::addShips(bool player, Ship* ship)
{
    if(player)
    {
	mPlayerShips.push_back(ship);
    }
    else
    {
	mComputerShips.push_back(ship);
    }
}//end addShips

Ship* Game::buildShip(char row, int col, char orient, Ship::ShipType type)
{
    switch(type)
    {
	case Ship::BATTLESHIP:
	{
	    return new Battleship(row,col,orient);
	}
	case Ship::CARRIER:
	{
	    return new Carrier(row,col,orient);
	}
	case Ship::CRUISER:
	{
	    return new Cruiser(row,col,orient);
	}
	case Ship::DESTROYER:
	{
	    return new Destroyer(row,col,orient);
	}
	case Ship::SUBMARINE:
	{
	    return new Submarine(row,col,orient);
	}
	
    }
    return NULL;
}//end buildShip

void Game::fillLocations()
{
    char rowChars[] = {'A','B','C','D','E','F','G','H','I','J'};
    char cur;

    for(int i = 0; i < MAX; i++)
    {
	cur = rowChars[i];
	for(int j = 0; j < MAX; j++)
	{
	    mPlayerLocations.push_back(Location(cur,j));
	    mCompLocations.push_back(Location(cur,j));
	}	
    }
}//end fillLocations

void Game::setLocations()
{
    int location_b, location_e;
    Ship* tmp;

    for(int i = 0; i < (int)mPlayerShips.size(); i++)
    {
	tmp = mPlayerShips[i];
	location_b = (tmp->getRowBegin()-65)*10 + tmp->getColBegin()-1;
	location_e = (tmp->getRowEnd()-65)*10 + tmp->getColEnd()-1;

	if(tmp->getRowBegin() == tmp->getRowEnd()) // horizontal
	{
	    setHorizontal(true, tmp, location_b, location_e);
	}
	else // vertical
	{
	    setVertical(true, tmp, location_b, location_e);
	}
    }

    for(int i = 0; i < (int)mComputerShips.size(); i++)
    {
	tmp = mComputerShips[i];
	location_b = (tmp->getRowBegin()-65)*10 + tmp->getColBegin()-1;
	location_e = (tmp->getRowEnd()-65)*10 + tmp->getColEnd()-1;

	if(tmp->getRowBegin() == tmp->getRowEnd()) // horizontal
	{
	    setHorizontal(false, tmp, location_b, location_e);
	}
	else // vertical
	{
	    setVertical(false, tmp, location_b, location_e);
	}
    }

}//end setLocations

void Game::setComputerShips()
{
    addShips(false, buildShip('A', 2, 'V', Ship::BATTLESHIP));
    addShips(false, buildShip('C', 5, 'H', Ship::CARRIER));
    addShips(false, buildShip('I', 1, 'H', Ship::CRUISER));
    addShips(false, buildShip('D', 7, 'V', Ship::CRUISER));
    addShips(false, buildShip('B', 6, 'H', Ship::DESTROYER));
    addShips(false, buildShip('G', 5, 'V', Ship::DESTROYER));
    addShips(false, buildShip('A', 4, 'H', Ship::SUBMARINE));

}//end setComputerShips

bool Game::removeShips()
{
    if((int)mPlayerShipCount == 0)
    {
	cout << "Computer has sunk all your ships" << endl;
	return true;
    }
    else if((int)mComputerShipCount == 0)
    {
	cout << "You have sunk all the computers ships, Congratulations!" << endl;
        return true;
    }

    

    return false;
}//end removeShips

void Game::setHorizontal(bool player, Ship* tmp, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
	if(player)
		mPlayerLocations[i].setInfo(tmp->getType());
	
	tmp->addLoc(i);  
    }
}//end setHorizontal

void Game::setVertical(bool player, Ship* tmp, int start, int end)
{
    for(int i = start; i <= end; i+=10)
    {
	if(player)
		mPlayerLocations[i].setInfo(tmp->getType());
	
	tmp->addLoc(i); 
    }
}//end setVertical






