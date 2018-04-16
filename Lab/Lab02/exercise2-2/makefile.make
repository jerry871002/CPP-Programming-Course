ex2-2.o: ex2-2.cpp ex2-2.h
	g++ -c ex2-2.cpp

ex2-2-main.o: ex2-2-main.cpp ex2-2.h
	g++ -c ex2-2-main.cpp

ex2-2: ex2-2.o ex2-2-main.o
	g++ ex2-2.o ex2-2-main.o -o ex2-2