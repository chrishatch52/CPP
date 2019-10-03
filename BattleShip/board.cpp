#include "board.h"

Board::Board()  // object does not contain data until init information processed
{ }

Board::~Board()
{ 
    //do nothing, no memory allocated 
}

void Board::printBoard(string name, vector<Location> locations_p, vector<Location> locations_c)
{
    char rowChars[] = {'A','B','C','D','E','F','G','H','I','J'};
    int playerIndex = 0, computerIndex = 0;

    system("clear");
    printNums();
    printHeader("Computer");

    for(int j = 0; j < 10; j++)
    {
	cout << rowChars[j] << " |";

    	for(int k = 0; k < 10; k++)
	    cout << " " << locations_c[computerIndex++].getInfo() << " ";

  	cout << "|" << endl;
    }

    printFooter();
    printNums();
    printHeader(name);

    for(int j = 0; j < 10; j++)
    {
	cout << rowChars[j] << " |";

    	for(int k = 0; k < 10; k++)
	    cout << " " << locations_p[playerIndex++].getInfo() << " ";

  	cout << "|" << endl;
    }

    printFooter();
}//end printBoard

void Board::printHeader(string name)
{
    // headers only differ in name printed so code is reused
    int length0;
    bool shorten = false;

    if((name.length()&1)!=0)
    {
	shorten = true;
    	length0 = ((horizLength - name.length())/2)+1;
    }
    else
        length0 = (horizLength - name.length())/2;

    cout << "  +";

    int length1 = (!shorten)? length0:length0-1;

    for(int i = 0; i < length1; i++)
	cout << "-";

    cout << name;

    for(int i = 0; i < length0; i++)
	cout << "-";

    cout << "+" << endl;
}//end printPlayerHeader

void Board::printFooter()
{
    cout << "  +";
    for(int i = 0; i < horizLength; i++)
	cout << "-";

    cout << "+" << endl;
}//end printFooter

void Board::printNums()
{
    int colNums[] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "   ";
    for(int i = 0; i < 10; i++)
	cout << " " << colNums[i] << " ";

    cout << endl;
}//end printNums








