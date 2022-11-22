#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include "umalloc.h"


static int ptr_to_mem = 0;
char init = '-';
char FREE = 'Y';
char NOTFREE = 'N';
static int init_arr = 0;


int free_blocks(size_t size){
  if(init_arr == 0){
      return 0;
  }
  int i = 0;
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    //void* data_block = (void*)&mem[i+sizeof(struct metadata)];
    if(curr_block->is_free != NOTFREE && curr_block->dataLength <= size){
        return 1;
    }
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
  return 0;
}

void* umalloc(size_t size){
    printf("we are inside malloc\n");
    
    printf("__________________________________________\n");

  printf("IN MALLOC\n");
  //check if there enough space for struct
  if((ptr_to_mem + size + sizeof(struct metadata)) > sizeof(mem)){
       return NULL;
  }

  //init char array if first call to malloc

  
  printf("SIZE OF SIZE PARAM %d\n", size);
  
  //create metadata

  //check for free blocks
  if(free_blocks(size) || init_arr == 0 ){

      if(init_arr == 0){
        printf("INIT SIZE OF MEM %d\n", sizeof(mem));
        //   memset(&mem,'-',sizeof(mem));
        init_arr = 1;
      }
     block* meta_data = (block*)mem;
     meta_data->dataLength = size;
     meta_data->is_free = NOTFREE;
  
  
     printf("SIZEOF STRUCT %d\n",sizeof(struct metadata));
     printf("SIZEOF SIZE %d\n", size);
     printf("ptr to mem before metadata %d\n",  ptr_to_mem );
     printf("after metadata %d\n",ptr_to_mem+sizeof(struct metadata));
    //get memory segment
    //int index_in_memory = ptr_to_mem+sizeof(struct metadata);
    //char* ptr_to_data = &(mem[index_in_memory]);
  
    char* ptr_to_data = mem+sizeof(block);
  
    printf("MALLOC RETURN VALUE %p\n", ptr_to_data );
  
  
    ptr_to_mem = ptr_to_mem + sizeof(struct metadata);
    ptr_to_mem = ptr_to_mem + size+1;
    return ptr_to_data;
    }else{
      return NULL;
    }
  //insert code here for that
 
 
  

  
  

  //For METRICS
 
 
 
   
}

/*
print all blocks in array
*/
void print_blocks(){
  printf("IN PRINT_BLOCKS\n");
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


int search_blocks(void* ptr){
  printf("MEMORY ADDRESS SEARCHING FOR %p\n",ptr);
  int i = 0;
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    void* data_block = (void*)&mem[i+sizeof(struct metadata)];
    if(data_block == ptr){
        printf("BLOCK FOUND\n");
        return 1;
    }
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
  return 0;
}


void free_block(void* ptr){
  int i = 0;
  printf("IN FREE BLOCKS\n");
  while(i < ptr_to_mem){
    block* curr_block = (block*)&mem[i];
    void* data_block = (void*)&mem[i+sizeof(struct metadata)];
    if(data_block == ptr){
        printf("BLOCK FOUND to free\n");
        curr_block->is_free = FREE;
        return;
    }
    i+= sizeof(struct metadata)+1+curr_block->dataLength;
  }
  return;
}
void ufree(void * ptr){
    printf("IN FREE\n");
    if(search_blocks(ptr) == 0){
       printf("NOTHING FOUND\n");
      return;
    }else{
        free_block(ptr);
    }

    // code for mergeing blocks

    
    return;
}