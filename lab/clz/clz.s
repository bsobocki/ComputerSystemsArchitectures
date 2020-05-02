    .text
    .globl	clz
	.type	clz, @function
clz:
    /* 
        deklaracja:
            extern int clz(uint64_t); 
        pomysł:
            wykonamy bin search aby znaleźć pierwszy zapalony bit, 
            wtedy liczba wiodących zer jest nam znana

            rekurencyjnie odwołamy się na liczbie %rdi

            %rdx <-- %rdi
            przesuwamy o wartość w %cl w lewo lub w prawo naszą liczbę w %rdx
            i sprawdzamy, czy większe od 0

            przesuwamy rdi w prawo o x --> sprawdzamy 64-x bitów starszych (tutaj to będą połowy kolejnych przedziałów)
            jesli połowa przedziału sprawdzanego jest równa 0 to dodajemy długość tego przedziału (bo tyle mamy zer z przodu)
            jednakze przesuneliśmy %rdi, więc musimy przywrócić je spowrotem i będziemy znowu przesuwać o dwukrotnie mniejszy przedział
            jeśli połowa sprawdzanego przedziału jest większa od 0 to znaczy że mamy tam zapalony bit, więc całą liczbę musimy skrócić o prawą część,
            ponieważ nie będzie nam ona potrzebna, szukamy pierwszej zapalonej jedynki w lewym przedziale, ponieważ znajduje się tam ona 
    */

    testq   %rdi, %rdi
    jz     .exit_64

    xorl    %eax,   %eax

.iteration:
    movq    %rdi,   %rdx    
    shrq    $32,    %rdi    
    testq   %rdi,   %rdi
    jnz     .check_16_bits

    addq    $32,   %rax
    movq    %rdx,   %rdi

.check_16_bits:  
    movq    %rdi,   %rdx    
    shrq    $16,    %rdi   
    testq   %rdi,   %rdi    
    jnz     .check_8_bits

    addq    $16,    %rax
    movq    %rdx,   %rdi

.check_8_bits:          
    movq    %rdi,   %rdx    
    shrq    $8,     %rdi    
    testq   %rdi,   %rdi    
    jnz     .check_4_bits

    addq    $8,     %rax
    movq    %rdx,   %rdi

.check_4_bits:
    movq    %rdi,   %rdx    
    shrq    $4,     %rdi    
    testq   %rdi,   %rdi    
    jnz     .check_2_bits

    addq    $4,     %rax
    movq    %rdx,   %rdi

.check_2_bits: 
    movq    %rdi,   %rdx    
    shrq    $2,     %rdi    
    testq   %rdi,   %rdi    
    jnz     .check_1_bits

    addq    $2,     %rax
    movq    %rdx,   %rdi

.check_1_bits:           
    movq    %rdi,   %rdx    
    shrq    $1,     %rdi   
    testq   %rdi,   %rdi    
    jnz     ._exit

    addq    $1,     %rax
    ret

.exit_64:
    movq    $64,    %rax    # dla 0 nie liczymy nic, zwracamy 64
._exit:
    ret

	.size	clz, .-clz
    
