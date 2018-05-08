#include <iostream>
#include <stdbool.h>
#include "Pair.h"
#include "IllegalCharException.h"



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

bool Pair::operator==(char other)const{
	 if(chr==other)
	    return true;
	  return false;

}

ostream& operator<<(ostream& os, Pair const& pr){
	os << pr.chr<<endl;
return os;
}
