#include <stdio.h>
#include <stdint.h>
#ifndef umalloc_h
#define umalloc_h
#define MEM_SIZE 10485760

extern char init;
extern char FREE;
extern char NOTFREE;


static char mem[MEM_SIZE];








#define malloc(x) umalloc(x)
#define free(y) ufree(y)

#pragma pack(1)
typedef struct metadata{
    
    int dataLength;
    char is_free;
    //struct metadata* next_block;
    
} block;

void* umalloc(size_t size);

void ufree( void * ptr );

#endif