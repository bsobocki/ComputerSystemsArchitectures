#include <stdio.h>
#include <stdint.h>

int32_t float2int(int32_t f) {
    int32_t  s = f >> 31;                   /* -1 jeśli znak był ujemny */
    int32_t  e = (f >> 23 & 255) - 127;     /* wykładnik po odjęciu bias */
    uint32_t m = f << 8 | 0x80000000;       /* mantysa 1.xxx... dosunięta do lewej */
    if (e == 255)                           /* e==255 - Nan */ 
        return 0x80000000;
    return (s << 31) | (m >> (31-e));                     /* teraz trzeba nam przesunąć tak, aby wiodąca jedynka znajdowala się na e-tej pozycji (od 0) */
}

void binary(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
    printf("\n");
} 

int main(){
    binary(float2int(0b01000010000000000000000000000000));
    binary(float2int(0b11000010111111100000000000000000));
    return 0;
}