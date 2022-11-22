#include "umalloc.h"
#define malloc(x) umalloc(x)
#define free(y) ufree(y)

int main(){
    printf("memgrind is here\n");
    void* a = malloc(sizeof(int));
    printf("void ptr %p\n",a);
    free(a);
    print_blocks();
}