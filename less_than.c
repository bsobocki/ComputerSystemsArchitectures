#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int less_than(int32_t x, int32_t y){
    return ( (x >> 1)-(y >> 1) - ( ~x & y & 1) ) >> 31;
}


int main(){
    int32_t x = 10;
    int32_t y = 30;
    printf("%d\n",less_than(x,y));

    x = 1341;
    y = 312;
    printf("%d\n",less_than(x,y));

    x = 131;
    y = 312;
    printf("%d\n",less_than(x,y));
}