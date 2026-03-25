board.o :	board.cxx
	g++ -c board.cxx

main.o :	main.cxx
	g++ -c main.cxx

view.o :	view.cxx
	g++ -c view.cxx

main:	main.o view.o board.o
	g++ main.o board.o view.o -o main_toto