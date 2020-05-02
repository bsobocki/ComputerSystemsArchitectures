        .text
        .globl  addsb
        .type   addsb, @function
addsb:
       /*
        Idea:
                będziemy wyciągać znaki liczb, ponieważ:
                        - dwie dodatnie i wynik ujemny ->  overflow +
                        - dwie ujemne i wynik dodatni  ->  overflow -
                        - różne znaki ->  brak overflow

                do pobierania znaków i ich usuwania wykorzystamy maski:
                        - %r10 = 10000000 10000000 10000000 ... <-- pobieranie znaków
                        - %r11 = 01111111 01111111 01111111 ... <-- usuwanie znaków

                wykorzystując moją poprzednią próbę rozwiązania i wyodrębnione z niej pomysły
                można przekształcić program na taki, który działa na całości - int64 bez konieczności dziąłania osobno
                na każdej liczbie int8

                najstarszy bit:
                1)    v1 & v2     <--  1 tam gdzie znaki ujemne
                2)    v1 ^ v2     <--  1 tam gdzie różne znaki
                3)  ~[ v1 | v2 ]  <--  1 tam gdzie dodatnie znaki (zanegowane tam, gdzie minimum jeden ujemny)
                
                wykonując AND %r10 mamy zapalone same najstarsze bity tam, gdzie trzeba

                1) = 1) & %r10
                2) = 2) & %r10
                3) = 3) & %r10

                aby sprawdzić dodawanie nie trzeba sprowadzać liczb do int8,
                wystarczy nam usunąć znak - dzięki temu unikniemy bitów przeniesienia
                pomiędzy liczbami int8, a nadal możemy sprawdzić overflow (poprzez znak dodawania)

                zwróćmy uwagę na dodawanie liczb ujemnych
                  1xxx xxxx
                + 1xxx xxxx
                -----------
                  syyy yyyy 

                widzimy że dodanie samych tylko znaków w wyniku daje nam 0 i bit przeniesienia
                więc to, czy wynik dodawania będzie ujemny czy dodatni zależy od młodszych bitów

                stąd nawet po usunięciu znaków mamy 0 na początku i to, czy na jego miejscu
                będzie 1 zależy od młodszych bitów

                a zatem możemy usunąć znaki i dodać liczby bez znaków, 
                a następnie korzystając z uprzednio wyodrębnionych znaków
                sprzwdzić, czy overflow nastąpił

                v1 = v1 & %r11
                v2 = v2 & %r11

                4)  v1 + v2  <--  dodawanie liczb bez znaków
                5)  [ ~ 4) & 1) ] & %r10  <--  10000000 dla overflow-, czyli dodatniego wyniku dodawania ujemnych liczb
                6)  [ 3) & 4) ]   <--- overflow+ jako 10000000
                7)  przesuwając 6) >> 7 mamy liczbę 1 jako int8 tam, gdzie overflow+
                8) %r10 - 7)
                        10000000 10000000 10000000 10000000
                      - 00000001 00000000 00000000 00000001
                      -------------------------------------
                        01111111 10000000 10000000 01111111
                    tam gdzie overflow+ mamy 01111111, 
                    stąd
                9) 8) & %r11 pozostawi nam tylko 01111111 tam, gdzie overflow+
                10)  9) | 5)  <--  do overflow- dorzucamy overflow+
                
                następnie chcemy utworzyć maskę, aby wyrzucić jakiekolwiek overflow,
                czyli pozyskać tylko dobre wyniki:

                        11)  [ 3) & 4) ] | 5)   <--- do overflow- jako 10000000 dorzucamy overflow+ jako 10000000,
                        czyli jakikolwiek overflow mamy jako 10000000

                        12) 11) >> 7 <--- 00000001 dla overflow
                        13) %r10 - 12) da nam 01111111 dla overflow o 10000000 dla dobrych wyników
                        14) 13) ^ %r10 da nam 11111111 dla overflow i 00000000 dla dobrych wyników
                        15) zapisujemy ~14) i mamy usunięte overflow

                po uzyskaniu maski w 15) możemy już złożyć nasz wynik:

                wynik: [ [ 4) & 15) ] ^ 2) ] | 10)  <--- do overflows dorzucamy dobre wyniki
           tylko dobre wyniki ^       ^usuwamy lub dodajemy jedynkę na przedzie tam, gdzie znaki są różne
                                        zmieniamy tam, gdzie mamy różne znaki, 
                                        tam, gdzie byłaby 1, a teraz jest 0 (bo nie dodaliśmy znaku jednej z liczb do wyniku)
                                        tam, gdzie byłoby 0, a teraz jest 1 (bo nie dodaliśmy znaku jednej z liczb - ujemnej)
       
       Używane rejestry i ich przeznaczenie:
       %rdi = v1
       %rsi = v2

        %r10 = $0x8080808080808080  <--- maska 10000000 10000000 ...
        %r11 = $0x7F7F7F7F7F7F7F7F  <--- maska 01111111 01111111 ...

        %r8  = 1)
        %r9  = 2)
        %rdx = 3)
        %rsi = 4)
        %rcx = 5)
        %rax = 6)
        %rax = 7)
        %rax = 8)
        %rax = 9)
        %rax = 10)
        %rdx = 11)
        %rdx = 12)
        %rdx = 13)
        %rdx = 14)
        %rdx = 15)
        %rdx = wynik
       */

        movq    $0x8080808080808080,     %r10
        movq    $0x7F7F7F7F7F7F7F7F,    %r11
        movq    %rdi,   %r8
        andq    %rsi,   %r8
        andq    %r10,   %r8     # 1)
        movq    %rdi,   %r9
        xorq    %rsi,   %r9
        andq    %r10,   %r9     # 2)
        movq    %rdi,   %rdx
        orq     %rsi,   %rdx
        notq    %rdx
        andq    %r10,   %rdx    # 3)
        andq    %r11,   %rdi    # v1 = v1 & %r11
        andq    %r11,   %rsi    # v2 = v2 & %r11
        addq    %rdi,   %rsi    # 4) na początku zamiast rsi wynik w rdx, ale brak rejestrów
        movq    %rsi,   %rcx
        notq    %rcx
        andq    %r8,    %rcx
        andq    %r10,   %rcx    # 5)
        movq    %rcx,   %r8
        movq    %rdx,   %rax
        andq    %rsi,   %rax    # 6)
         movq    %rax,   %rdx    # [ 3) & 4) ] %rdx jako 3) się już nie przyda
        shrq    $7,     %rax    # 7)
        negq    %rax
        addq    %r10,   %rax    # 8)
        andq    %r11,   %rax    # 9)
        orq     %rax,   %rcx    # 10)
        orq     %r8,   %rdx    # 11)
        shrq    $7,     %rdx    # 12)
        negq    %rdx
        addq    %r10,   %rdx    # 13)
        xorq    %r10,   %rdx    # 14)
        notq    %rdx            # 15)
        andq    %rsi,   %rdx    # 4) & 15)
        xorq    %r9,    %rdx    # [ 4) & 15) ] ^ 2)
        orq     %rdx,   %rcx    # [ [ 4) & 15) ] ^ 2) ] | 10) -- wynik 
        movq    %rcx,   %rax
        /* używałem wcześniej %r15 co spowodowało, że sprawdzaczka brała do sprawdzania
        zawartość tego rejestru jako rsi i sama obliczała wyniki
        i biorąc mój wynik już wskazywała na błąd.

        przez to długi czas nie mogłem zrozumieć dlaczego mimo, iż poprzednie wersje kodu działają 
        to na sprawdzaczce nie.
        stąd opóźnienie chwilowe z wysłaniem ostatecznej działającej wersji 

        jeśli można to proszę o zaliczenie zadania mimo lekkiego opóźnienia */
        
        ret

        .size   addsb, .-addsb
