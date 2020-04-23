#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t my_abs(int32_t x){
    printf("znak = %d   ",x>>30); // for numbers x < 0   x>>30 == -1, in the other case == 0 
    return  ((x>>30)|1)*x;
}

int32_t my_abs_2(int32_t x){
    return (x^x>>31)-(x>>31);
}

int main(){
    printf("|%d| == %d\n", -133, my_abs_2(-133));
    printf("|%d| == %d\n", 133, my_abs_2(133));
    printf("|%d| == %d\n", 0, my_abs_2(0));
    printf("|%d| == %d\n", -3127489, my_abs_2(-3127489));
    printf("|%d| == %d\n", 8402, my_abs_2(8402));
    printf("|%d| == %d\n", -111, my_abs_2(-111));
}