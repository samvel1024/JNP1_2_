#include "strset.h"
#include <stdio.h>
#include "hidden.h"
void print_stuff();

int main(){
    printf("Compiled from C\n");
    print_stuff();
    call_hidden();
    return 0;
}