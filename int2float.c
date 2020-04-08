#include <stdio.h>
#include <stdint.h>

int32_t int2float(int32_t i) {

    /*
    przykład: int32_t =  00000000000000000000000101011101  =
    = 2^8 + 2^6 + 2^4 + 2^3 + 2^2 + 2^0 = 2^8 (1 + 2^-2 + 2^-4 + 2^-5 + 2^-6 + 2^-8) =
    = 2^8 * 1.01011101  
    czyli: 
        e = 8 + 127 (trzeba uwzględnić bias)
        m = 1.01011101 
        s = 0

    kolejny przykład -127 = -1 * (2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0) = 
    = -1 * 1.111111 * 2^6 (czyli przesunięcie bitowe o 6 w lewo) 
    */

    /* znak - sign: 
    -1 jeśli znak był ujemny */
    int32_t s = i >> 31; 

    /* jesli i jest ujemna to otrzymaliśmy już znak,
    a chcemy znaleźć wiodącą jedynkę, która nie oznacza znaku */
    if (s == -1) {
        i = -i;
        s = 1;
    }

    /* pozycja:
    __builtin_clz zwraca liczbę zer wiodących
    więc mozemy policzyć pozycje wiodącej jedynki 
    odejmując od 32 wynik __builtin_clz(i) */
    int32_t p = 32 - __builtin_clz(i);

    /* wykładnik - exponent: 
    po odjęciu 1 (bo chcemy numerować bity od 0, by i-ty bit oznaczał 2^i w sumie)
    i dodaniu bias (obliczając wykładnik trzeba go odejmować)
    mamy nasz wykładnik */
    int32_t bias = 127;
    int32_t e = p - 1 + bias;   

    /* tworzymy maskę, aby wyeliminować wiodącą jedynkę, aby mieć tylko mantysę
    więc przesuwamy 1 na pozycję p i wtedy odejmujemy 1, aby na prawo od p były same 1*/
    int32_t mask = (1<<(p-1))-1;

    /* eliminujemy wiodącą jedynkę */
    i &= mask; 

    /* guard, round i sticky 
    potrzebne nam będą do zaokrąglenia round-to-even */
    int32_t 
        guard  = 0,
        round  = 0,
        sticky = 0; 

    /* zaokrąglamy, gdy pozycja p jest większa niż 23, 
    ponieważ na prawo od niej znajduje się wtedy za dużo bitów na mantysę */
    if (p > 24) {
        /* ostatni bit mantysy jest na pozycji 23 na prawo od p ( p - 23 ) 
        więc jeśli chcemy dostać się do tego bitu to przesuniemy o (p - 23) - 1 
        bo aby dostać się do bitu k-tego przesuwamy o k-1 w prawo */
        guard  = ( i >> (p - 23 - 1) ) & 1;
        /* bit round jest o 1 w prawo od bitu guard */
        round  = ( i >> (p - 23 - 2) ) & 1;
        /* sticky bit to OR bitów na prawo od round 
        więc 1 przesuwamy na pozycję round i odejmujemy 1
        więc aby wziąć OR, wystarczy sprawdzić czy liczba jest większa od 0*/
        sticky = ( i & ( ( 1 << (p - 23 - 2) ) - 1 ) ) > 0; 
    }

    /* mantysa - fraction:
    chcemy, aby miejsce wiodącej jedynki znajdowało się na 24 pozycji od prawej,
    aby na najmniej znaczących 23 bitach znajdowała się mantysa
    musimy dosunąć 
        w lewo o tyle ile brakuje nam do 24 pozycji (jeśli p < 24)
        w prawo o tyle ile jesteśmy za daleko do 24 pozycji (jeśli p >= 24) */
    int32_t f = 
        ( p < 24 ? (i << (24 - p)) : (i >> (p - 24)) ) + 
        ((guard & round) | (round & sticky)) ;

    return (s << 31) + (e << 23) + f ;
}

void binary(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
    printf("\n");
} 

int main(){
    binary(int2float(0b1110110110101100001000));
    binary(int2float(32));
    binary(int2float(-127));
    return 0;
}