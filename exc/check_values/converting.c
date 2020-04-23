#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int pred_1(int32_t x, int32_t y, int32_t z, double dx, double dy, double dz){
    return (float)x == (float)dx;
}

int pred_2(int32_t x, int32_t y, int32_t z, double dx, double dy, double dz){
    return dx - dy == (double)(x - y);
}

int pred_3(int32_t x, int32_t y, int32_t z, double dx, double dy, double dz){
    return (dx + dy) + dz == dx + (dy + dz);
}

int pred_4(int32_t x, int32_t y, int32_t z, double dx, double dy, double dz){
    return (dx * dy) * dz == dx * (dy * dz);
}

int pred_5(int32_t x, int32_t y, int32_t z, double dx, double dy, double dz){
    return dx / dx == dz / dz;
}



int main (){

    return 0;
}