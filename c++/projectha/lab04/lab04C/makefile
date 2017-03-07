all:bintree.x

FLAGS= -ggdb -std=c++11 -g #-wall -wextra

run:
	./bintree.x < test

BinSearchTree.o: BinSearchTree.hpp BinSearchTree.cpp
	g++ $(FLAGS) -c BinSearchTree.cpp -o BinSearchTree.o

main.o:	main.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(FLAGS) -c main.cpp -o main.o 

bintree.x:main.o BinSearchTree.o
	g++ $(FLAGS) main.o  BinSearchTree.o -o bintree.x
clean:
	rm -f *.o *.x *~
