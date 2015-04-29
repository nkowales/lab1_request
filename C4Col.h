//Nathan Kowaleski
//Lab 1 part 1
//connect four
//Column Class
//C4col.h file
// 4/22/15

#ifndef C4COL_H
#define C4COL_H

#include<iostream>
using namespace std;


class C4Col
{

public:

C4Col();
//~C4Col(){};
int isFull();
char getDisc(int);
int getMaxDiscs();
void addDisc(char);


private:

int total;
int max;
char player[64];

};

#endif
