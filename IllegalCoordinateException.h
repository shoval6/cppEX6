
#ifndef ILLEGALCOORDINATEEXCEPTION_HPP_
#define ILLEGALCOORDINATEEXCEPTION_HPP_
#include <string>

using namespace std;


class IllegalCoordinateException{

private:
int i;
int j;

public:
IllegalCoordinateException(int i,int j);
string theCoordinate()const;

};





#endif /* ILLEGALCOORDINATEEXCEPTION_HPP_ */
