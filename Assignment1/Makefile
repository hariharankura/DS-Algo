all: bitmagic

bitmagic: bitmagic.o
	gcc bitmagic.o -o bitmagic

bitmagic.o: bitmagic.c
	gcc -c bitmagic.c

clean:
	rm *.o bitmagic