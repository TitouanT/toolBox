CC = gcc
FLAGS = -Wall

all: cyph

clear: clean

clean:
	rm -rf cyph *.o

mrproper: clean all

cyph: main.o sha256.o
	$(CC) $(FLAGS) $^ -o $@

main.o: main.c sha256.h
	$(CC) $(FLAGS) -c $<

sha256.o: sha256.c sha256.h
	$(CC) $(FLAGS) -c $<

