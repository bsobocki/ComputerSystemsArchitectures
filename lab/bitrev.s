	.globl	bitrev
	.type	bitrev, @function
bitrev:
    /*
        // odwracamy pary bitów
    1)  x = ((x & 0xaaaaaaaaaaaaaaaa) >> 1)  | ((x & 0x5555555555555555) << 1);
        
        // odwrócone pary bitów zamieniamy miejscami (odwrócone czwórki)
    2)  x = ((x & 0xcccccccccccccccc) >> 2)  | ((x & 0x3333333333333333) << 2);
        
        // odwrócone czwórki zamieniamy miejscami
    3)  x = ((x & 0xf0f0f0f0f0f0f0f0) >> 4)  | ((x & 0x0f0f0f0f0f0f0f0f) << 4);
        
        // odwrócone ósemki zamieniamy miejscami
    4)  x = ((x & 0xff00ff00ff00ff00) >> 8)  | ((x & 0x00ff00ff00ff00ff) << 8);
        
        // odwrócone szesnastki zamieniamy miejscami
    5)  x = ((x & 0xffff0000ffff0000) >> 16) | ((x & 0x0000ffff0000ffff) << 16);
        
        // odwracamy trzydziestki dwójki i mamy wynik
    6)  return (x >> 32) | (x << 32);

        powyższy kod odpowiada:
        @x - liczba
        @n - liczba bitów do odwrócenia
        
        uint bit_rev(uint x, int n){
            
            // jeśli mamy 2 bity to zwracamy odwrócone 2 bity
            if (n==2)
                return x<<1 | x>>1;

            // dzielimy liczbę na 2 części - górne bity i dolne
            uint high_half = h_bits(uint x);
            uint low_half = l_bits(uint x);
            
            // odwracamy je - przykład 1100 0100  ->   0011 0010
            uint rev_high_half = bit_rev(high_half, n/2);
            uint rev_low_half = bit_rev(low_half, n/2);

            // zamieniamy miejscami odwrócone bity
            return (rev_high_half >> n/2 ) | (bit_rev(low_half, n/2) << n/2 );
            
            przykład: 11000100
            11000100  -> 1100 0100
            1100 0100 -> 0011 0010
            0011 0010 -> 0010 0011
            return 00100011 
        }

        // po wywołaniu:
        bit_rev(uint x, 64);

        wywołania rekurencyjne zejdą w dół, dopóki nie dojdzie do n == 2
        zamieni nam dwójki
        zamieni dwójki miejscami - odwrócone czwórki
        zamieni czwórki miejscami - odwrócone ósemki
        zamieni ósemki miejscami - odwrócone szesnastki
        zamieni szesnastki miejscami - odwrócone 32 bitowe liczby
        zamieni 32 bitowe słowa - odwrócone 64 bity 
        
        czyli tak, jak w powyższym kodzie c++

        powyższy kod napisany w assemblerze:
    */
    movq %rdi,  %rdx                     /* temp1 <-- x */
    movq $0xaaaaaaaaaaaaaaaa, %rax
    andq %rax,   %rdi                    /* x & 0xaaaaaaaaaaaaaaaa */
    shrq $1,    %rdi                     /* x >> 1 */
    movq $0x5555555555555555, %rax
    andq %rax,   %rdx                    /* x & 0x5555555555555555 */    
    shlq $1,     %rdx                    /* x << 1 */
    orq  %rdx,   %rdi                    /* 1) zapisane w %rdi */
    movq %rdi,  %rdx                     /* temp1 <-- x po 1) */
    movq $0xcccccccccccccccc, %rax
    andq %rax,  %rdi                     /* x & 0xcccccccccccccccc */
    shrq $2,    %rdi                     /* x >> 2 */
    movq $0x3333333333333333, %rax
    andq %rax,  %rdx                     /* x & 0x3333333333333333 */
    shlq $2,    %rdx                     /* x << 2 */
    orq  %rdx,   %rdi                    /* 2) zapisane w %rdi */
    movq %rdi, %rdx                      /* temp1 <-- x po 2) */
    movq $0xf0f0f0f0f0f0f0f0, %rax
    andq %rax,  %rdi                     /* x & 0xf0f0f0f0f0f0f0f0 */
    shrq $4,    %rdi                     /* x >> 4 */
    movq $0x0f0f0f0f0f0f0f0f, %rax
    andq %rax,  %rdx                     /* x & 0x0f0f0f0f0f0f0f0f */
    shlq $4,    %rdx                     /* x << 4 */
    orq  %rdx,   %rdi                    /* 3) zapisane w %rdi */
    movq %rdi, %rdx                      /* temp1 <-- x po 3) */
    movq $0xff00ff00ff00ff00, %rax
    andq %rax,   %rdi                    /* x & 0xff00ff00ff00ff00 */
    shrq $8,    %rdi                     /* x >> 8 */
    movq $0x00ff00ff00ff00ff, %rax
    andq %rax,   %rdx                    /* x & 0x00ff00ff00ff00ff */
    shlq $8,    %rdx                     /* x << 8 */
    orq  %rdx,   %rdi                    /* 4) zapisane w %rdi */
    movq %rdi, %rdx                      /* temp1 <-- x po 4) */
    movq $0xffff0000ffff0000, %rax
    andq %rax,   %rdi                    /* x & 0xffff0000ffff0000 */
    shrq $16,    %rdi                    /* x >> 16 */
    movq $0x0000ffff0000ffff, %rax
    andq %rax,   %rdx                    /* x & 0x0000ffff0000ffff */
    shlq $16,    %rdx                    /* x << 16 */
    orq  %rdx,   %rdi                    /* 5) zapisane w %rdi */
    movq %rdi, %rdx                      /* temp1 <-- x po 5) */
    shrq $32, %rdi                       /* x >> 32 */
    shlq $32, %rdx                       /* x << 32 */
    movq %rdi, %rax                          
    orq  %rdx, %rax                      /* 6) */
    ret

	.size	bitrev, .-bitrev
