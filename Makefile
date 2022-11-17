OBJS	= umalloc.o memgrind.o
SOURCE	= umalloc.c memgrind.c
HEADER	= umalloc.h
OUT	= test
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

memgrind: memgrind.o umalloc.o
	gcc memgrind.o umalloc.o -o memgrind
umalloc.o: umalloc.c umalloc.h
	$(CC) $(FLAGS) umalloc.c 

memgrind.o: memgrind.c
	$(CC) $(FLAGS)  memgrind.c 


clean:
	rm -f $(OBJS) $(OUT)