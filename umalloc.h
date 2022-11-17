#include <stdio.h>



char init = '-';

#pragma pack(1)
typedef struct metadata{
    
    int dataLength;
    char is_free;
    //struct metadata* next_block;
    
} block;

void *umalloc(size_t size);

void ufree( void * ptr );

