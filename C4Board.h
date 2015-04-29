//Nathan Kowaleski
//lab 1 part 2
//connect four
//connect four board
//C4Board.h file
// 4/22/15

#ifndef C4BOARD_H
#define C4BOARD_H

#include<iostream>
#include"C4Col.h"
using namespace std;


class C4Board
{

public:

C4Board();
//~C4Board(){};
void display();
void play();
int otherMove();//computer's move

private:

int numcol;
C4Col board[64];
int hasWon();//end condition check

};

#endif
