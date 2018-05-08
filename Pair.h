#pragma once

#include<iostream>
using namespace std;

#ifndef PAIR_HPP_
#define PAIR_HPP_

class  Pair{
public:
	int x;
	int y;
	char chr;
	Pair();
	Pair(int x,int y);
	Pair& operator=(char chr);
    bool operator==(char other)const;
    friend ostream& operator<< (ostream& os, Pair const& pr);

private:
};

#endif /* PAIR_HPP_ */
