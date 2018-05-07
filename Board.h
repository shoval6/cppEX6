#pragma once
#include "Pair.h"
using namespace std;


#ifndef BOARD_HPP_
#define BOARD_HPP_




class Board{

	Pair** array2D;
	int size;

public:

Board(int length);
Board(const Board& other);
~Board();
Pair& operator[](const Pair& pt) ; //const std::pair<int,int>& Index
Board& operator=(char chr);
Board& operator=(const Board& other);
void initial();
void copy(const Board &other);
void free();
friend ostream& operator<<(ostream& os, const Board& br);

};



#endif /* BOARD_HPP_ */
