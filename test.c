#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
int32_t x = -214;
x = 214;
printf("%d", -x>>31);
}