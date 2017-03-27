CC = gcc
FLAGS = -Wall

all: test_256

clean:
	rm -rf *.o
	rm -rf test_256

clear: clean

mrproper:
	make clean
	make all

test_256: sha256_example.o sha256.o
	$(CC) $(FLAGS) $^ -o $@

sha256_example.o: sha256_example.c sha256.h
	$(CC) $(FLAGS) -c $<

sha256.o: sha256.c sha256.h
	$(CC) $(FLAGS) -c $<
