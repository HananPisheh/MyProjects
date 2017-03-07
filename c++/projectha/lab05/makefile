screen.x:main.cpp screen.o snake.o getChar.o
	g++ -std=c++11 -ggdb -o screen.x  main.cpp screen.o cell.o snake.o getChar.o -lcurses -ltermcap
snake.o: snake.cpp  snake.hpp cell.o
	g++ -c -std=c++11 -ggdb snake.cpp  -o snake.o
screen.o: screen.cpp  screen.hpp cell.o
	g++ -c -std=c++11 -ggdb screen.cpp  -o screen.o
getChar.o: getChar.cpp  getChar.hpp
	gcc -c -std=c++11 -ggdb getChar.cpp -o getChar.o
cell.o: cell.hpp cell.cpp
	g++ -c -std=c++11 -ggdb cell.cpp -o cell.o
clean:
	/bin/rm -f screen.x screen.o cell.o snake.o getChar.o *~
