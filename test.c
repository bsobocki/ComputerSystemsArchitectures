#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
int32_t x = -2147483648;
int32_t y = -1;
int32_t s = x + y;
printf("\n\n%d\n\n%d", (s-y == x) , s);
}