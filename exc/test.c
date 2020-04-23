#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

union  {
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union elem *next;
    } e2;
}elem;

int main(){
    printf("size of union elem: %d", sizeof(elem));
}