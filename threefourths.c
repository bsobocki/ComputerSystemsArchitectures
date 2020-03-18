/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
            Uzupełnij ciało funkcji zadeklarowanej następująco:
            
            // Oblicz x * 3/4 zaokrąglając w dół. 
            int32_t threefourths(int32_t x);
        
            Nie można dopuścić do wystąpienia nadmiaru i niedomiaru!

        EN:
            Write function:

            // calculate the floor of the  x * 3/4 
            int32_t threefourths(int32_t x);

            Over and under deficiency must not be allowed!

*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int32_t threefourths(int32_t x){
    // get the last 2 bits
    // the rest modulo of the x / 4 is on the last 2 bits
    int32_t modulo = x & 3;

    // x % 4 == 0   =====> the result is 3*(x>>2)
    // x % 4 == 1   =====>  x = 4k + 1  =====>  (12k + 3) / 4  == l + 3/4
    // 3/4 < 1 so the floor of the x * 3/4 is equal to (x>>2) * 3 
    int32_t result = (x>>2)*3;

    // x % 4 == 2   =====>  x = 4k + 2  =====> (12k + 6) / 4  == l + 6/4
    // 1 < 6/4 < 2 so the floor of the x * 3/4 is equal to (x>>2) * 3 + 1
    if (modulo == 2) 
        result += 1;

    // x % 4 == 3   =====>  x = 4k + 3  =====> (12k + 9) / 4  == l + 9/4
    // 2 < 9/4 < 3 so the floor of the x * 3/4 is equal to (x>>2) * 3 + 2
    if (modulo == 3)
        result += 2;

    return result;
}


void print_threefourths(int32_t x){
    printf("%d * 3/4 = %d\n", x, threefourths(x));
}


int main(){
    print_threefourths(10);
    print_threefourths(100);
    print_threefourths(4*100 + 3);
    print_threefourths(4*10 + 1);
    print_threefourths(4*200120 + 2);
    print_threefourths(2147483647);
    print_threefourths(-2147483648);
}