CC=g++
CFLAGS=-std=c++17 -O2

.PHONY: all clean install uninstall

all: hello_there_general_kenobi

clean: 
	rm *.o hello_there_general_kenobi

install:
	install ./hello_there_general_kenobi /usr/local/bin

uninstall:
	rm /usr/local/bin/hello_there_general_kenobi

general.o: ../01_gk/general.cpp ../01_gk/general.hpp
	$(CC) $(CFLAGS) -c ../01_gk/general.cpp -o general.o

kenobi.o: ../01_gk/kenobi.cpp ../01_gk/kenobi.hpp
	$(CC) $(CFLAGS) -c ../01_gk/kenobi.cpp -o kenobi.o

hello_there_general_kenobi: main.cpp general.o kenobi.o ../01_gk/general.hpp ../01_gk/kenobi.hpp
	$(CC) $(CFLAGS) main.cpp general.o kenobi.o -o hello_there_general_kenobi

