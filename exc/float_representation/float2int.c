#include <stdio.h>
#include <stdint.h>

void binary(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
    printf("\n");
} 

int32_t float2int(int32_t f) {
    int32_t  s = (f >> 31 | 1);                 /* -1 jeśli znak był ujemny */
    int32_t  e = (f >> 23 & 255) - 127;         /* wykładnik po odjęciu bias */
    uint32_t m = f << 8 | 0x80000000;           /* mantysa 1.xxx... dosunięta do lewej */
    if (e > 31 || (e == 31 && (m & 0x7FFFFFFF) != 0)) /* zbyt duże e oznacza przesuniecie 1.xxx o e w prawo, czyli nadmiar */
        return 0x80000000;   
    s*=(e>=0);                    
    return s * (m >> (31 - e));                 /* teraz trzeba nam przesunąć tak, aby wiodąca jedynka znajdowala się na e-tej pozycji (od 0) */
}

void test(int32_t x){
    int32_t res = float2int(x);
    printf("%d = ",res);
    binary(res);
}

int main(){
    test(0b01001010011011011010110000100000);
    test(0b01000010000000000000000000000000);
    test(0b11000010111111100000000000000000);
    test(0b01000010111111100000000000000000);
    test(0b01000001010100000000000000000000);
    test(0b01000100100110111010000000000000);
    test(0b01000010010111000000000000000000);
    test(0b01000101010100100111000000000000);
    test(0b01000011011010000000000000000000);
    test(0b01000011001000010000000000000000);
    test(0b01000111110000111000001010000000);
    test(0b11000100100110111010000000000000);
    test(0b11000010010111000000000000000000);
    test(0b11000101010100100111000000000000);
    test(0b11000011011010000000000000000000);
    test(0b11000011001000010000000000000000);
    test(0b11000111110000111000001010000000);
    printf("\n\n");
    test(0b01111111100000000100000010000000);
    return 0;
}
