LIB = -lSDL2 -lSDL2_image
CC = gcc

test_izi.out: easySdl2.o test.o
	gcc $^ -o $@ $(LIB)

easySdl2.o: easySdl2.c easySdl2.h
	gcc -c $<

test.o: test.c easySdl2.h
	gcc -c $<

clean: clear

clear:
	rm -f *.o *.out

mrproper: clear
	make