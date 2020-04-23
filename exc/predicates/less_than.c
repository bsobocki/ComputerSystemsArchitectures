#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int less_than(int32_t x, int32_t y){
    return -( ( (x >> 1)-(y >> 1) - ( ~x & y & 1) ) >> 31);
}


int main(){
    int32_t x = 10;
    int32_t y = 30;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 1341;
    y = 312;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 131;
    y = 312;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = -1314;
    y = -312;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = -1314;
    y = 312;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 1314;
    y = -312;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 0;
    y = 0;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 1;
    y = 1;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = -3;
    y = 3;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = -10;
    y = 10;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 3;
    y = -3;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 10;
    y = -10;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = 2147483647;
    y = -2147483648;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));

    x = -2147483647;
    y = 2147483647;
    printf("%d < %d ? %d\n",x,y,less_than(x,y));
}