/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
            Napisz ciąg instrukcji, który bez użycia dodatkowych zmiennych, zamieni miejscami zawartość zmiennych «x» i «y»

        EN:
            Write code that will swap values of the variables «x», «y» without using any additional variable.

*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void swap(int32_t * x, int32_t * y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main(){
    int32_t x = 100;
    int32_t y = 3;
    printf("before swap(x,y):\n\tx=%d\n\ty=%d\n", x, y);
    swap(&x, &y);
    printf("after swap(x,y):\n\tx=%d\n\ty=%d\n", x, y);

    x = 2147483647; 
    y = 2147483640;
    printf("before swap(x,y):\n\tx=%d\n\ty=%d\n", x, y);
    swap(&x, &y);
    printf("after swap(x,y):\n\tx=%d\n\ty=%d\n", x, y);
}