/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
            Czy poniższe wyrażenia zawsze obliczą się do prawdy dla dwóch dowolnych wartości zmiennych «x» i «y» typu «int32_t»? 
            Jeśli nie to podaj wartości, które prowadzą do obliczenia fałszu.
                • (x > 0) || (x - 1 < 0)
                • (x & 7) != 7 || (x << 29 < 0)
                • (x * x) >= 0•x < 0 || -x <= 0
                • x > 0 || -x >= 0•(x | -x) >> 31 == -1
                • x + y == (uint32_t)y + (uint32_t)x
                • x * ~y + (uint32_t)y * (uint32_t)x == -x

        EN:
            Will the following expressions always calculate TRUE for any two values of variables «x» i «y» of type «int32_t»? 
            If not, give values that lead to the calculate FALSE.
                • (x > 0) || (x - 1 < 0)
                • (x & 7) != 7 || (x << 29 < 0)
                • (x * x) >= 0
                • x < 0 || -x <= 0
                • x > 0 || -x >= 0•(x | -x) >> 31 == -1
                • x + y == (uint32_t)y + (uint32_t)x
                • x * ~y + (uint32_t)y * (uint32_t)x == -x

*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int predicate_1(int32_t x){
    return (x > 0) || (x - 1 < 0);
} 

int predicate_2(int32_t x){
    return (x & 7) != 7 || (x << 29 < 0);
} 

int predicate_3(int32_t x){
    return (x * x) >= 0;
} 

int predicate_4(int32_t x){
    return x < 0 || -x <= 0;
} 

int predicate_5(int32_t x){
    return x > 0 || -x >= 0;
}

int predicate_6(int32_t x){
    return (x | -x) >> 31 == -1;
}

int predicate_7(int32_t x){
    int32_t y = -2148473648; // this y makes that for each value 'x' the predicate will not be satisfied 
    return x * ~y + (uint32_t)y* (uint32_t)x == -x;
}




void print_values(int (*pred)(int32_t x)){
    int32_t x = 0;
    while( x>=0 ){
        if( !pred(x) ) printf("%d\n",x);
        x++;
    }
    x = 0;
    while( x<=0 ){
        if( !pred(x) ) printf("%d\n",x);
        x--;
    }
    printf("\n------\n");
}