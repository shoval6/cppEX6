a.out: Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o
	clang++-5.0 -std=c++17 Board.o IllegalCoordinateException.o IllegalCharException.o Pair.o -o a.out
Pair.o: Pair.cpp Pair.h
	clang++-5.0 -std=c++17 -c Pair.cpp
Board.o: Board.cpp Board.h
	clang++-5.0 -std=c++17 -c Board.cpp
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	clang++-5.0 -std=c++17 -c IllegalCharException.cpp
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	clang++-5.0 -std=c++17 -c IllegalCoordinateException.cpp
clean:
	rm *.o a.out
