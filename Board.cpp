#include <iostream>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

Board::Board(int size) {
	create(size);

}

Board::Board(const Board& other){
	create(other.tsize);
	for (int i = 0; i < other.tsize; i++)
			for (int j = 0; j < other.tsize; j++)
				array2D[i][j] = other.array2D[i][j];
}

Board::~Board() {
	free();
}

void Board::create(int size) {
	tsize = size;
	array2D = new Pair*[tsize];
	for (int i = 0; i < tsize; ++i)
				array2D[i] = new Pair[tsize];


}

ostream& operator<<(ostream& os, const Board& br) {
	for (int i = 0; i < br.tsize; i++) {
		for (int j = 0; j < br.tsize; j++) {
			os << br.array2D[i][j].chr;
		}
		os << "" << endl;
	}
	return os;
}

Pair& Board::operator[](const Pair& pt) {
	if (pt.x < 0 || pt.x >= tsize || pt.y < 0 || pt.y >= tsize)
		throw IllegalCoordinateException(pt.x, pt.y);
	return array2D[pt.x][pt.y];

}

Board& Board::operator=(char chr) {
	if (chr != '.')
		throw IllegalCharException(chr);
	initial();
	return *this;

}

Board& Board::operator=(const Board& other) {
	if(this != &other){
	if (tsize != other.tsize) {
			free();
			create(other.tsize);

	}
			for (int i = 0; i < other.tsize; i++)
						for (int j = 0; j < other.tsize; j++)
							array2D[i][j] = other.array2D[i][j];


	}
	return *this;
}

void Board::free() {
	for (int i = 0; i < tsize; i++)
		delete[] array2D[i]; // delete array within matrix
	delete[] array2D;  // delete actual matrix

}

void Board::initial() {
	for (int i = 0; i < tsize; i++)
		for (int j = 0; j < tsize; j++)
			array2D[i][j].chr = '.';
}

