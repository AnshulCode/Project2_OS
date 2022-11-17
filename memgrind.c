#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <ucontext.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#define STACK_SIZE 16384
#define malloc(x) umalloc(x)
#define free(y) ufree(y)

int main() {
 
  void* a = malloc(sizeof(int));
  printf("RETURNED ADDREESS %p\n", a);
    pretty_print();
  void* b = malloc(sizeof(int));
  printf("RETURNED ADDREESS %p\n", b);
    pretty_print();
  void* c = malloc(sizeof(int));
  printf("RETURNED ADDREESS %p\n", c);
    pretty_print();
  void* d = malloc(sizeof(int));
  printf("RETURNED ADDREESS %p\n", d);
    pretty_print();
  //pretty_print();
  //free(d);
  print_blocks();
  /*
  int* b = (int *)(&a);
  *b = 10;
  printf("IN the main %p\n");
  printf("STORED INT %d\n",*b);
  
  */
  

 
 
  
  
  
  return 0;
}