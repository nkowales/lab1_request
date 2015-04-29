//Nathan Kowaleski
//Lab 1 part 1
//connect four
//Column Class
//C4Col.cpp file
// 4/22/15

#include<iostream>
#include"C4Col.h"
using namespace std;


//default constructor
C4Col::C4Col()
{

total=0;
max=6;

for(int i = 0; i < max; i++)//fill in array with space characters
{

	player[i]=' ';

}//end for i

}//end constructor


//return value of the nth element in the column
char C4Col::getDisc(int n)
{

if((n < max) && (n >= 0))//if input exists in number of rows
{

	return player[n];

}//end if

else
{

	cout << "Invalid input to getDisc!" << endl;
	return ' ';

}//end else

}//end getDisc


//returns max number of discs in column
int C4Col::getMaxDiscs()
{

return max;

}//end getMaxDiscs


//check if column is full
int C4Col::isFull()
{

if(total<max)//if current total is less than max then is not full
{

	return 0;

}//end if

else
{

	return 1;

}//end else

}//end isFull


//add disc to column
void C4Col::addDisc(char c)
{

if(!(c == 'X' || c == 'O'))//if character not one of the two designated 
{

cout << "Invalid input to addDisc!" << endl;

}//end if

else if(!isFull() )//if column isn't full
{

	player[total] = c;
	total++;
 
}//end else if

else
{

	cout << "Column is full." << endl;

}//end else

}//end addDisc
