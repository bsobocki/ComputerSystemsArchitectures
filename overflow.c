#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int overflow(int32_t x, int32_t y){
    return (x ^ (1<<31) ) + (y ^ (1<<31));
}

int main(){
    printf("will %d + %d give us an overflow? %d", 2147483647 , 3, overflow(2148473647, 3));
}