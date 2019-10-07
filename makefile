 
#target: dependencies
#	action

# Based on "Make help" video under resources in canvas

langAnt: antMain.o antMenu.o displayBoard.o Ant.o validMax.o
	g++ antMain.o antMenu.o displayBoard.o Ant.o validMax.o -o langAnt

antMain.o: antMain.cpp
	g++ -c antMain.cpp

antMenu.o: antMenu.cpp antMenu.hpp
	g++ -c antMenu.cpp

displayBoard.o: displayBoard.cpp displayBoard.hpp
	g++ -c displayBoard.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

validMax.o: validMax.cpp validMax.hpp
	g++ -c validMax.cpp

clean:
	rm *.o langAnt
