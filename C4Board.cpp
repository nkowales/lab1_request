//Nathan Kowaleski
//lab 1 part 2
//connect four
//connect four board
//board .cpp file
// 4/22/15

#include<iostream>
#include"C4Col.h"
#include"C4Board.h"
using namespace std;


//default constructor
C4Board::C4Board()
{

numcol=7;

}//close constructor


//display current connect 4 board 
void C4Board::display()
{

cout << endl << "  | ";

for(int k = 1; k <= numcol; k++)//label number columns
{

	cout << k << " | ";

}//end for k
 
cout << endl;

int x = 1;//label number rows

for(int i = board[0].getMaxDiscs()-1; i >= 0; i--)//for all rows top to bottom
{

	cout << x << " | ";
	x++;

	for(int j = 0; j < numcol; j++)//for all columns left to right
	{

		cout << board[j].getDisc(i) << " | ";

	}//end for j
	
	cout<<endl;

}// end for i

cout << endl;

}//end display


//determine move of computer player, first available column
int C4Board::otherMove()
{

for(int m = 0; m < numcol; m++)//for all columns
{

	if(!(board[m].isFull() ) )//if column is not full
	{
	
		return(m + 1);// + 1 because first column is board[0]
	
	}//end if

}//end for m

return(-1);//if all columns full return -1 to quit;

}//end otherMove


//check to see if any connections of 4
int C4Board::hasWon()
{

if((numcol < 4) || (board[0].getMaxDiscs() < 4))//if less than 4 rows or columns
{

	return 1;//say someone has won if only to get play function to exit the while loop.

}//end if

char p; //character piece

for(int i = 0; i < board[0].getMaxDiscs(); i++)//for all rows
{

	for(int j = 0; j < numcol - 3; j++)//for all columns but last 3, prevent out of bounds
	{
	
		p = board[j].getDisc(i);//store value of piece so less typing

		if(p != ' ')//if spot is not empty, no point checking for 4 empty spots in a row
		{
		
			if(p == board[j + 1].getDisc(i) && p == board[j + 2].getDisc(i) && p == board[j+3].getDisc(i))//if four in a row in a row
			{
			
				return 1;
			
			}//end if
		
		}//end if
	
	}//end for j

}// end for i

for(int m = 0; m < board[0].getMaxDiscs() - 3; m++)//for all rows but last 3, prevent out of bounds
{

	for(int n = 0; n < numcol; n++)//for all columns
	{
	
		p = board[n].getDisc(m);//store value of piece so less typing

		if(p != ' ')//if spot is taken, no point checking for 4 empty spots in a row
		{
		
			if(p == board[n].getDisc(m + 1) && p == board[n].getDisc(m + 2) && p == board[n].getDisc(m + 3))// if four in a row in a column
			{
			
				return 1;
			
			}//end if 
			
		}//end if
	
	}//end for n

}//end for m

for(int v = 0; v < numcol - 3; v++)//for all columns but last 3
{

	for(int w = board[0].getMaxDiscs() - 1; w > 2; w--)//for all rows but bottom 3
	{
	
		p = board[v].getDisc(w);//store value of piece so less typing

		if(p != ' ')//if spot is taken, no point checking for 4 empty spots in a row
		{
		
			if(p == board[v + 1].getDisc(w - 1) && p == board[v + 2].getDisc(w - 2) && p == board[v + 3].getDisc(w - 3))//check for connect 4 in diagonals that go top right to bottom left.
			{
			
				return 1;
			
			}//end if
		
		}//end if
		
	}//end for w

}//end for v

for(int x = numcol - 1; x > 2; x--)//for all columns but first 3
{

	for(int y = board[0].getMaxDiscs() - 1; y > 2; y--)//for all rows but bottom 3
	{
	
		p = board[x].getDisc(y);//store value of piece so less typing

		if(p != ' ')//if spot is taken, no point checking for 4 empty spots in a row
		{
		
			if(p == board[x - 1].getDisc(y - 1) && p == board[x - 2].getDisc(y - 2) && p == board[x - 3].getDisc(y - 3))//check for connect 4 in diagonals that go top right to bottom left.
			{
			
				return 1;
			
			}//end if
		
		}//end if
		
	}//end for w

}//end for v

return 0;//if no connect 4 found then no one has won yet

}//end hasWon


//play function allows two players to play connect four by inputting to command line.
void C4Board::play()
{

int turn=0;
int col;
int z = 1;
int isOther = 1;//1 if two player, 0 if against computer 
cout << "If you are playing another person(or yourself) please enter 1, otherwise enter 0 to play against a computer." << endl;
cin >> isOther;

if(!(isOther == 1 || isOther == 0))//if isOther is not 1 or 0, set to 1
{

	cout << "Invalid input! defaulting to two player mode" << endl;
	isOther = 1;

}//end if

while(z)
{

	display();
	if( ( ( (turn % 2) + 1) == 1) || (isOther == 1))//if player one's turn or no computer player
	{

		cout << "Player " << ( (turn % 2) + 1) <<  ", which column would you like place a piece in? or enter -1 to quit" << endl;
		cin >> col;

	}//end if
	
	else
	{
	
		col = otherMove();
	
	}//end else
	
	if(col == -1)//if user desires to end game
	{
		
		z = 0;
	
	}//end if

	else if( ( (turn % 2) + 1) == 1)//if player 1's turn;
	{

		board[col - 1].addDisc('X');
		
		if(hasWon())//if move won game
		{
		
			cout << "Player 1 has won the game!" << endl;
			z = 0;
		
		}//end if

	}//end else if

	else//player 2's turn
	{

	board[col - 1].addDisc('O');
	
	if(hasWon())//if move won game
		{
		
			cout << "Player 2 has won the game!" << endl;
			z = 0;
		
		}//end if

	}//end else

	turn++;

}//end while	
	
display();
cout << "The game ended during turn " << turn << endl << endl; 	
	
}//end play
