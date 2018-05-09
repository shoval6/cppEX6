#pragma once
#include "Pair.h"
using namespace std;


class Board{

	Pair** array2D;
	int tsize;

public:

Board(int length);
Board(const Board& other);
~Board();
Pair& operator[](const Pair& pt) ; //const std::pair<int,int>& Index
Board& operator=(char chr);
Board& operator=(const Board& other);
void initial();
void create(int size);
void free();
friend ostream& operator<<(ostream& os, const Board& br);
};

