#include <iostream>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

Board::Board(int length) :
	array2D(new Pair*[length]), size(length) {
	for (int i = 0; i < size; ++i)
		array2D[i] = new Pair[size];
}

Board::Board(const Board& other) :
	array2D(new Pair*[other.size]), size(other.size) {
	copy(other);
}

Board::~Board() {
	free();
}

void Board::copy(const Board &other) {
	this->size = other.size;
	for (int i = 0; i < size; ++i)
		array2D[i] = new Pair[size];
	for (int i = 0; i < other.size; i++)
		for (int j = 0; j < other.size; j++)
			array2D[i][j] = other.array2D[i][j];

}

ostream& operator<<(ostream& os, const Board& br) {
	for (int i = 0; i < br.size; i++) {
		for (int j = 0; j < br.size; j++) {
			os << br.array2D[i][j].chr;
		}
		os << "" << endl;
	}
	return os;
}

Pair& Board::operator[](const Pair& pt) {
	if (pt.x < 0 || pt.x >= size || pt.y < 0 || pt.y >= size)
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
	if (this != &other) {
		if (this->size == other.size)
			copy(other);
		else {
			free();
			size = other.size;
			array2D = new Pair*[size];
			copy(other);
		}
	}
	return *this;
}

void Board::free() {
	for (int i = 0; i < size; i++)
		delete[] array2D[i]; // delete array within matrix
	delete[] array2D;  // delete actual matrix

}

void Board::initial() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			array2D[i][j].chr = '.';
}

