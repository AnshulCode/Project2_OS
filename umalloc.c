#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include "umalloc.h"


static int ptr_to_mem = 0;


static char mem[1000000] = {0};
static int memory_left = sizeof(mem);
static int memory_taken = 0;
static char* pointer_to_mem;
static void* return_val;
static int init_arr = 0;





void* umalloc(size_t size);

void* umalloc(size_t size){


  printf("IN MALLOC\n");
  //check if there enough space for struct
  if((ptr_to_mem + size + sizeof(struct metadata)) > sizeof(mem)){
       return NULL;
  }

  //init char array if first call to malloc
  if(init_arr == 1){
    memset(&mem,'-',sizeof(mem));
  }
  //create metadata

  //check for free blocks
  //insert code here for that

  block* meta_data = (block*)&mem[ptr_to_mem];
  meta_data->dataLength = size;
  meta_data->is_free = 'N';
  
  printf("__________________________________________\n");
  printf("SIZEOF STRUCT %d\n",sizeof(struct metadata));
  printf("SIZEOF SIZE %d\n", size);

  //get memory segment

  void* ptr_to_data = (void*)&mem[ptr_to_mem+sizeof(struct metadata)];
  ptr_to_mem += sizeof(struct metadata);
  ptr_to_mem += size+1;
  
  memory_taken += sizeof(struct metadata)+size+1;
  // check if there is room for next meta_data block

  memory_left -= sizeof(struct metadata) + size +1;
 
 
  return ptr_to_data;
}



void pretty_print(){
    printf("Bytes REMAINING: %d\n" , memory_left);
    printf("Bytes TAKEN: %d\n" , memory_taken);
}

/*
print all blocks in array
*/
void print_blocks(){
  int i = 0;
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    printf("___________________________________________\n");
    printf("ADDRESS OF MEMORY BLK META %p\n", curr_block);
    printf("BLOCK SIZE %d\n", curr_block->dataLength);
    printf("IS FREE %c\n", curr_block->is_free);
    printf("___________________________________________\n");
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
}

/*


Searches through all blocks of metadata
return 1 on success, 0 on failure

*/
int search_blocks(void* ptr){
 // printf("MEMORY ADDRESS SEARCHING FOR %p\n",ptr);
  int i = 0;
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    void* data_block = (void*)&mem[i+sizeof(struct metadata)];
    if(data_block == &ptr){
        printf("BLOCK FOUND\n");
        return 1;
    }
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
  return 0;
}
/*

*/
void free_blocks(void* ptr){
  int i = 0;
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    void* data_block = (void*)&mem[i+sizeof(struct metadata)];
    if(data_block == &ptr){
        printf("BLOCK FOUND to free\n");
        curr_block->is_free = 'Y';
        return 1;
    }
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
  return 0;
}

void ufree(void * ptr){
 
    
    
}