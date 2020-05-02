#include <stdio.h>
#include <stdint.h>

extern uint64_t addsb(uint64_t, uint64_t);

void bin(uint64_t n) { 
    for (uint64_t i = 1ULL << 63; i > 0; i = i >> 1) 
        (n & i)? printf("1"): printf("0"); 
    printf("\n");
}

void test(uint64_t x, uint64_t y){
    printf("  ");
    bin(x);
    printf("+ ");
    bin(y);
    printf("  ----------------------------------------------------------------\n  ");
    bin(addsb(x,y));
}

int main(){
    test(0x00000000000011ff, 0x000000000000ef00);
    test(0x000000000000117f, 0x0000000000001f80);
    return 0;
}
