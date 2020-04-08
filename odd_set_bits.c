/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
           Uzupełnij ciało funkcji zadeklarowanej poniżej.
           
           // Kiedy x zawiera nieparzystą liczbę jedynek zwróć 1, w p.p. 0 
           int32_t odd_ones(uint32_t x);

        EN:
            Write function with header:

            // When x have odd number of set bits return 1, 0 in the other case
            int32_t odd_ones(uint32_t x);

*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t odd_ones(uint32_t x){
    x = x^(x>>1);
    x = (x^(x>>2)) & 0x11111111;
    x = x * 0x11111111;
    return (x>28) & 1;
}

void test(uint32_t x, int res, int num){
    printf("have %d odd number of '1'?  %d\n", x, odd_ones(x));
    printf("^\n| should be %d, because the number of '1' is equal: %d\n\n", res, num);
}

int main(){
    test(0b11111100000000000000111111000001, 1, 13); // 13 x '1'
    test(0b00000000000000000000111111111111, 0, 12); // 12 x '1'
    test(0, 0, 0); // 0 x '1'
    test(0b110011, 0, 4); // 4 x '1'
    test(0b111, 1, 3); // 3 x '1'
    test(0b1110101010101010101, 1, 11); // 11 x '1'
}