#include "ship.h"

void Ship::printSinkingReport(bool player)
{
    string attacker, defender;

    if(player)
    {
        attacker = "You";
	defender = "the Computer's ";
    }
    else
    {
        attacker = "The Computer";
	defender = "your ";
    }
    
    cout << attacker << " sunk " << defender << mType_s << endl; 
    cout << "\nPress Enter to continue" << endl;
    cin.ignore();
}//end printResult

void Ship::setInfo(char row, int col, char orient)
{
    mRowBegin = row;
    mColBegin = col;
    if(orient=='V') // ship occupies a column
    {
	mRowEnd = row+(mHitCount-1);
	mColEnd = col;
    }
    else  // ship occupies a row
    {
	mRowEnd = row;
	mColEnd = col+(mHitCount-1);
    }
}//end setInfo

char Ship::getType()
{
    char types[] = {'B','C','U','D','S'};
    char type_c;

    switch(mType)
    {
	case BATTLESHIP:
	{
		type_c = types[0];
		break;
	}
	case CARRIER:
	{
		type_c = types[1];
		break;
	}
	case CRUISER:
	{
		type_c = types[2];
		break;
	}
	case DESTROYER:
	{
		type_c = types[3];
		break;
	}
	case SUBMARINE:
	{
		type_c = types[4];
		break;
	}
	default:
	{
		type_c = ' ';
		break;
	}
    }

    return type_c;
}//end getType

void Ship::addLoc(int i)
{
    mLocations.push_back(i);
}//end addLoc

bool Ship::containsLoc(int loc)
{
    for(int i = 0; i < (int)mLocations.size(); i++)
    {
	if(mLocations[i] == loc)
		return true; 
    }

    return false;
}//end containsLoc
