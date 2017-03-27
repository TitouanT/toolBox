CC = gcc
FLAGS = -Wall

all: test_512

clean:
	rm -rf *.o
	rm -rf test_512

clear: clean

mrproper:
	make clean
	make all

test_512: sha512_example.o sha512.o
	$(CC) $(FLAGS) $^ -o $@

sha512_example.o: sha512_example.c sha512.h
	$(CC) $(FLAGS) -c $<

sha512.o: sha512.c sha512.h
	$(CC) $(FLAGS) -c $<
