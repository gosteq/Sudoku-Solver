LIBS=
OPTIONS= -O1
hello: sudokusolver.o Stack.o main.o
	g++ $(OPTIONS) $(LIBS) sudokusolver.o Stack.o main.o -o hello

main.o: main.cpp
	g++ $(OPTIONS) $(LIBS) -c main.cpp -o main.o

Stack.o: Stack.cpp
	g++ $(OPTIONS) $(LIBS) -c Stack.cpp -o Stack.o
	
sudokusolver.o: sudokusolver.cpp
	g++ $(OPTIONS) $(LIBS) -c sudokusolver.cpp -o sudokusolver.o

clean:
	rm -rf main.o Stack.o sudokusolver.o hello
