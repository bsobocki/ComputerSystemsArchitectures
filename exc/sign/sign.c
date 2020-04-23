#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int i_sign(int32_t x){
    return -(-(x>>31)|(-x>>31)); // dla dodatnich (-x>>31) daje nam 0, dla dodatnich -1
}

int u_sign(uint32_t x){
    return (-x>>31);
}

void test(int32_t x){
    printf("sign of the int32_t %d is: %d\n", x, i_sign(x));
}

void u_test(uint32_t x){
    printf("sign of the uint32_t %d is: %d\n", x, u_sign(x));
}

int main(){
    test(-123);
    test(0);
    test(123);
    test(-3);
    test(-19301);
    test(123451);
    test(-123451);
    printf("\n-----------\n\n");
    u_test(2134098);
    u_test(123u);
    u_test(0);
    u_test(2345);
    u_test(23490);
    u_test(4582);
}