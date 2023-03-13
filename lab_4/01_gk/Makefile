general_kenobi: main.o general.o kenobi.o
	g++ main.o general.o kenobi.o -o general_kenobi

main.o: main.cpp general.hpp kenobi.hpp
	g++ main.cpp -c -o main.o

general.o: general.cpp general.hpp
	g++ general.cpp -c -o general.o

kenobi.o: kenobi.cpp kenobi.hpp
	g++ kenobi.cpp -c -o kenobi.o

