/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
            Zmienne i, k spełniają warunek 0 ≤ i,k ≤ 31. 
            Napisz fragment kodu, który skopiuje  i-ty  bit zmiennej x na pozycję  k-tą

            pozcja liczy się od lewej od 1 do 32

        EN:
            Variables i, k satisfy the condition 0 ≤ i, k ≤ 31.
            Write the code, that copies i-th bit of the variable x to the k-th position

            position is counting by left from 1 to 32
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* binary representation of the number */
char* bits(uint32_t num){
    size_t number_of_bits = sizeof(num) * 8; // 4 bytes * 8 bits = 32 bits
    char * bits = malloc(number_of_bits);  // allocate char [32]
    for (size_t i=0; i<32; i++) bits[i] = '0';  // set each bit to 0
    int i = 31;
    
    while(num){
        if (num & 1) bits[i] = '1'; // if the i-th bit == 1
        i--;
        num >>= 1; // cut the last bit
    }
    
    return bits;
}

uint32_t reset_kth_bit(uint32_t num, size_t k){
    return num & ~(1 << (32-k));
}

/* copy i-th bit to k-th position */
uint32_t copy_ith_bit_to_kth_pos(uint32_t x, size_t i, size_t k){
    // position == position from left
    uint32_t mask = 1<<(32-i);
    // get i-th bit
    uint32_t ith_bit = x & mask;
    // move ith bit to the kth position
    uint32_t ith_bit_on_kth_pos = k>i ? ith_bit>>(k-i) : ith_bit<<(i-k); 

    x = reset_kth_bit(x, k);
    return x | ith_bit_on_kth_pos; // logical OR will copy the value on the moved bith to the x
}


int main(){
    printf("%s\n", bits(copy_ith_bit_to_kth_pos(0b00000000100000000000000000000000, 9, 3)));
    printf("%s\n", bits(copy_ith_bit_to_kth_pos(0b11111111011111111111111111111111, 9, 8)));
    printf("%s\n", bits(copy_ith_bit_to_kth_pos(4, 32-2, 32)));
    return 0;
}