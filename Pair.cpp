#include <iostream>

#include "Pair.h"
#include "IllegalCharException.h"
using namespace std;



Pair::Pair(){
	this->chr = '.';

}

//Pair::Pair(char chr) : chr(chr){}


Pair::Pair(int x,int y) : x(x),y(y){}


Pair& Pair::operator=(char chr){
	if (chr != 'X' && chr != 'O' && chr != '.')
		throw IllegalCharException(chr);
	this->chr = chr;

	return *this;
}
