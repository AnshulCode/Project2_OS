memgrind: memgrind.o umalloc.o
	gcc memgrind.o umalloc.o -o memgrind

memgrind.o : memgrind.c
	gcc -c memgrind.c

umalloc.o:umalloc.c umalloc.h
	gcc -c umalloc.c

clean:
	rm -f memgrind *.o