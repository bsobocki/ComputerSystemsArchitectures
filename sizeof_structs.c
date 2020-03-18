/*
    @author: 
        Bartosz Sobocki
    @course:
        PL: Architektury Systemów Komputerowych  
        EN: Computer Systems Architectures
    @task:
        PL:
            Podaj rozmiar w bajtach poniższych struktur przyjmując, że wskaźnik jest 32-bitowy. 
            Pod jakim przesunięciem,  względem  początku  struktury,  znajdują  się  poszczególne  pola?  
            Jak  zreorganizować  pola struktury, by zajmowała mniej miejsca? 
            Z czego wynika takie zachowanie kompilatora?

            struct A {          struct B {
                int8_t a;           uint16_t a;
                void *b;            double b;
                int8_t c;           void *c;
                int16_t d;      };
            };
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct A {
    int8_t a;
    void *b;
    int8_t c;
    int16_t d;
} A;

typedef struct B {
    uint16_t a;
    double b;
    void *c;
} B;


// organize from the bieggest to the lowest
typedef struct A1 {
    void *b;    // 8
    int16_t d;  // 2
    int8_t a;   // 1
    int8_t c;   // 1
} A1;           // 8 > 12 > 16, so sizeof( A1 ) == 16

typedef struct B1 {
    double b;   // 8
    void *c;    // 8
    uint16_t a; // 2
} B1;           // 18  and 16 > 18 > 24, so 

typedef struct C{ int a;} C;
typedef struct C0{ char a;} C0;
typedef struct C1{ int a,b;} C1;
typedef struct C2{ int a; char b;} C2;
typedef struct C3{ char a; char b;} C3;
typedef struct C4{ char a; char b; char c; char d; int s;} C4; // 8 bytes withoud padding
typedef struct C5{ char a; char b; char c; char d; char e; int s;} C5; // 12 bytes, because 8 + 1 > 8 and compiler want to have 4n size (?)

typedef struct bytes32{
    void * a;   // 8
    void * b;   // 8
    int16_t c;  // 2
    int32_t d;  // 4
    int32_t e;  // 4
}bytes32;       // 24 > 26 > 32  => size == 32

typedef struct bytes40{
    bytes32 b;    // 32
    int8_t i;     // 1
}bytes40;         // 32 > 33 > 40  => size == 40

typedef struct bytes48{
    bytes40 b;    // 40
    int8_t i;     // 1
}bytes48;         // 40 > 41 > 48  => size == 48

typedef struct bytes56{
    bytes48 b;    // 56
    int8_t i;     // 1
}bytes56;         // 48 > 49 > 56  => size == 56



int main(){
    printf("A: %d bytes\n",sizeof(A));
    printf("B: %d bytes\n",sizeof(B));
    printf("A1: %d bytes\n",sizeof(A1));
    printf("B1: %d bytes\n\n",sizeof(B1));

    A a;
    a.a = 9;
    a.b = NULL;
    a.c = 5;
    a.d = 4;

    printf("A.a: %d bytes\n", sizeof(a.a));
    printf("A.b: %d bytes\n", sizeof(a.b));
    printf("A.c: %d bytes\n", sizeof(a.c));
    printf("A.d: %d bytes\n", sizeof(a.d));



    printf("\n--------\n");

    printf("double: %d bytes\n", sizeof(double));
    printf("uint8_t: %d bytes\n", sizeof(uint8_t));
    printf("float: %d bytes\n", sizeof(float));
    printf("void *: %d bytes\n", sizeof(void *));
    printf("void: %d bytes\n", sizeof(void));

    printf("\n--------\n");

    printf("C: %d bytes\n", sizeof(C));
    printf("C0: %d bytes\n", sizeof(C0));
    printf("C1: %d bytes\n", sizeof(C1));
    printf("C2: %d bytes\n", sizeof(C2));
    printf("C3: %d bytes\n", sizeof(C3));
    printf("C4: %d bytes\n", sizeof(C4));
    printf("C5: %d bytes\n", sizeof(C5));

    printf("\n--------\n");

    /* STRUCTS NAMES FOR 64-bit COMPILER !   ---->   compiling flag:  -m64   */
    printf("bytes32: %d bytes\n", sizeof(bytes32));
    printf("bytes40: %d bytes\n", sizeof(bytes40));
    printf("bytes48: %d bytes\n", sizeof(bytes48));
    printf("bytes56: %d bytes\n", sizeof(bytes56));
    return 0;
}