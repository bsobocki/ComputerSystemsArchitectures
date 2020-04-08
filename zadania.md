# Ćwiczenia z ASK, grupa AKr

## Lista ćwiczeniowa 2 (18.03.2020)


:::info
Przed rozpoczęciem zajęć wszyscy studenci powinni dołączyć do grupy na serwerze Discorda za pomocą poniższego linka
`https://discord.gg/VFWgvn`.
Konieczne jest wcześniejsze założenie konta oraz zainstalowanie aplikacji, gdyż jest to potrzebne do udostępniania własnego ekranu.
Proszę się podpisywać tak, żeby każdy mógł was łatwo zidentyfikować.
:::

:::info
W czasie trwania pierwszych dwóch części, czyli od 12:00 do 13:00, studenci (głównie Ci, którzy będą później prezentować rozwiązania) powinni być dostępni na serwerze, aby inni studenci oraz prowadzący mogli się z nimi łatwo połączyć i zadawać pytania.
W czasie trwania ostatniej części, czyli od 13:00 do 14:00, wszyscy studenci powinni aktywnie słuchać prezentowanych rozwiązań.
:::



## Deklaracje (do 12:00)

:::info
Dopisz do poniższej tabelki wiersz z deklarowanymi przez Ciebie zadaniami, koniecznie **przed** godziną **12:00**. O tej godzinie zostaną wybrane osoby do opracowania konkretnych zadań.
:::

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie X w odpowiedniej kolumnie!

|                      | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| -------------------- | - | - | - | - | - | - | - | - | - |
| Artur Kraska         | x |   |   | x |   |   |   |   | x |
| Anna Karykowska      | x | x | x |   | x |   | x | x | x |
| Wiktoria Kuna        | x | x | x |   | x | x | x | x | x |
| Piotr Stokłosa       | x | x | x |   | x |   | x | x | x |
| Jakub Bok            | x | x | x |   |   |   | **x** | x | x |
| Bartosz Morasz       | x | x | x |   |   | x | x | x | x |
| Antoni Pokusiński    | x | x | x |   |   | **x** | x | x | x |
| Mateusz Rec          | x | x | x |   |   |   | x | x | x |
| Kamil Galik          | x | **x** | x |   | x |   | x | x | x |
| Gabriela Niemyjska   | x | x |   |   | x | x | x |   |   |
| Michal Myczkowski    | x | x | x |   | **x** |   | x |   |   |
| Bartosz Sobocki      | x | x |   |   | x | x | x | **x** |   |
| Dominik Danelski     | x | x | **x** |   |   |   | x | x |   |
| Piotr Mańkowski      |   | x |   |   |   |   | x |   | x |
| Jan Wańkowicz        | x | x | x | x | x |   | x | x | x |
| Bartłomiej Salachna  | x | x | x | **x** | x | x | x | x | x |
| Bartosz Głowacki     | **x** | x |   |   |   |   | x |   | x |
| Marcin Szmagara      | x | x | x | x | x |   | x | x | **x** |

## Rozwiązania (12:00 - 12:30)

:::info
Studenci wybrani do opracowania zadań (ich imiona będą widoczne pod numerami zadań) powinni w ciągu tych 30 minut uzupełnić ich rozwiązania. Jeśli zadanie wymaga posłużenia się diagramem, to można wkleić jego zdjęcie. 
:::


### Zadanie 1

:::success
Autor: Bartosz Głowacki i Michał Myczkowski
:::

<miejsce na rozwiązanie>

Treść zadania:
Czy poniższe wyrażenia zawsze obliczą się do prawdy dla dwóch dowolnych wartości zmiennych«x» i «y» typu «int32_t»? Jeśli nie to podaj wartości, które prowadzą do obliczenia fałszu

1) (x > 0) || (x - 1 < 0)
to będzie fałsz na minimalnej wartości int ponieważ wtedy x < 0 a x-1 to maksymalna wartość int zatem
x-1 > 0
2) (x & 7) != 7 || (x << 29 < 0)
to będzie zawsze prawda ponieważ (x & 7) != 7 to będzie prawdziwe zawsze jeśli reszta z dzielenia 
liczby x przez 8 będzie różna od 7. (x << 29 < 0) to natomiast będzie prawdziwe zawsze kiedy trzeci
bit liczby będzie jedynką bo wtedy po przesunięciu o 29 stanie się 32 bitem więc liczba będzie ujemna.
a w przypadku kiedy reszta z dzielenia przez 8 liczby x jest równa 7 to 3 bit jest zapalony, więc 
wtedy (x << 29 < 0) będzie prawdziwe
3) (x * x) >= 0
to dla wielu przypadków nie będzie prawdziwe wystarczy aby int się przekręcił do liczby ujemnej 
przykładowo przekręci się dla x = 46341 jest to pierwiastek z maksymalnej liczby możliwej do zapisania 
w int zaokrąglony do góry
4) x < 0 || -x <= 0
to jest zawsze prawda ponieważ -0 = 0 i każda liczba dodatnia ma swoją liczbę przeciwną
zatem -0 <= 0 to prawda oraz dla każdej liczby ujemnej prawdą będzie x < 0 a dla każdej dodatniej prawdą 
będzie -x <= 0
5) x > 0 || -x >= 0
to nie będzie prawda dla minimalnej wartości int ponieważ nie ma ona swojej liczby przeciwnej w 
zakresie inta i -x w tym przypadku będzie równa x zatem będzie < 0

6) (x | -x) >> 31 == -1
Nie zachodzi dla x = 0
bo zarowno 0 i -0 ma pierwszy od lewej bit  = 0

7) x + y == (uint32_t)y + (uint32_t)x
najpierw wykona sie dodawanie signed po lewej
potem wykona sie dodawanie unsigned po prawej
przy porownaniu lewa strona zostanie rzutowana na unsigned (przy rzutowaniu pozostaje ten sam "bit pattern") a dodawanie wyglada tak samo
przy unsigned i signed wiec sa sobie rowne zawsze

8) x*~y + (uint32)y * (uint32_t)x == -x
zawsze prawda poniewaz mozemy sobie rozpisac
~y jako -y - 1 i otrzymujemy
x*(-y -1) + uy*ux
czyli
-xy -x + uy*ux
-xy sie skraca z +uy*ux
i zostaje -x
### Zadanie 2

:::success
Autor: Kamil Galik
:::

Zadanie polega na tym, że musimy zamienić wartości 2 zmiennych bez używania dodatkowych zmiennych.
Jako że możemy wykorzystywać operatory bitowe to można to zrobić za pomocą XORów tak jak poniżej.

```c=
x = x ^ y;
y = x ^ y;
x = x ^ y;
```
Pierwszy XOR znajduje nam miejsca na których liczby x i y się różnią.
Gdy użyjemy XORa drugi raz, to bity liczby y różniące się względem liczby x podmienią swoje wartości i w zmiennej y będzie zapisana wartość x.
Przy trzecim użyciu analogicznie tylko w zmiennej x zapisujemy wartość y.
### Zadanie 3

:::success
Autor: Dominik Danelski
:::

Niedomiar lub nadmiar zajdzie gdy wynikiem sumowania dwóch liczb o tym samym znaku będzie liczba o przeciwnym znaku. Dodatkowe &1 jest spowodowane tym, by po przesunięciu o 31 zostawało 0 lub 1 zamiast liczby ujemnej. Pierwsza część (przed alternatywą bitową) szuka niedomiaru, a druga - nadmiaru. W wypadku ich wystąpienia powinna zwrócić 1, w pp. 0.

```c=
((x>>31) & 1) & ((y>>31) & 1) & ~((x+y)>>31) | ~(x>>31) & ~(y>>31) & ((x+y)>>31)

lepiej:
( ((x&y) & ~(x+y) | ~(x|y) & (x+y)) >> 31 ) & 1 // chcemy operować na pierwszym bicie od lewej a potem to przesunąc i AND z 1

```

Zawsze można trochę skrócić sprawdzając czy x, y są tego samego znaku, a s przeciwnego. (:

### Zadanie 4

:::success
Autor: Bartłomiej Salachna
:::

```c=
0x7F7F7F7F -> 01111111011111110111111101111111
0x80808080 -> 10000000100000001000000010000000
```
W obu przypadkach najpierw maskujemy najbardziej znaczący bit i wykonujemy zwykłe operacje na reszcie. Następnie osobno wyznaczamy najbardziej znaczący bit i go wstawiamy.

1. Dodawanie:
```c=
s = (x & 0x7F7F7F7F) + (y & 0x7F7F7F7F)
s = ((x ^ y) | 0x80808080) ^ s
```
2. Odejmowanie:
```c=
s = (x | 0x80808080) - (y & 0x7F7F7F7F)
s = ~( ((x ^ y) | 0x7F7F7F7F) ^ s)
```
chcemy dodawać tak, żeby nie było bitów przechodzących, zatem najpierw nie bierzemy pod uwagę tych bitów po lewej, bierzemy 011111111
potem po prostu dodajemy XORem, bo XOR to dodawanie bez tego znaku przechodzącego


### Zadanie 5

:::success
Autor:  Michal Myczkowski
:::

```c=
int32_t threefourths(int32_t x)
{
    //najpierw liczymy reszte z dzielenia x/4
    //przesuwajac x w prawo o 2 bity dostajemy floor(x/4)
    //przesuwajac x w lewo o 2 bity dostajemy 4*floor(x-4)
    //a wiec reszta to:
    int32_t reszta = x - ((x >> 2) << 2);
    //mnozymy 3 razy reszte i robimy podloge z dzielenia tego przez 4
    int32_t dodaj = (reszta + reszta + reszta) >> 2;
    //bierzemy teraz floor(x/4)
    x = x >> 2;
    //zwracamy 3*floor(x/4) + 3*floor(reszta/4)
    return x + x + x + dodaj;
}
```

### Zadanie 6

:::success
Autor: Antoni Pokusiński
:::
- x,y - unsigned int
     (~x&y) |((~x|y) & (x-y))
    
    
    Dzięki temu wyrażeniu,**na najstarszym bicie** uzyskamy odpowiedź
    (pisząc np (x-y)31 mam na myśli najstarszy bit liczby (x-y))
    1: (~x&y) - sprawdza przypadek gdy y31=1 i x31=0 (czyli oczywiscie x<y)
    2: (~x|y) - niespełnione jedynie gdy x31=1 i y31=0 (czyli oczywiście x>y)
    3: (x-y) - tutaj trzeba rozważyć więcej możliwości:
       GDY X<Y:
       gdy  y31=1 i x31=1 to x-y ma wartosc co najmniej 0x80000001 czyli (x-y)31=1, 
        gdy y31=0 i x31=0 wtedy (x-y) równe co najmniej 0x80000001 czyli (x-y)31=1, 
        gdy y31=0 i x31=1, to sprzeczne z X<Y
        gdy y31=1 i x31=0, to już sprawdzone w 1
        GDY X = Y
        (x-y)31 =0 czyli ok
        GDY X>Y
        gdy x31=1 i y31=0, to już rozważone
        gdy x31=1 i y31=1, to w najgorszym przypadku gdy odejmujemy 0xFFFFFFFF - 0x80000001, to (x-y)31=0,czyli ok
        gdy x31=0 i y31=0, to analogicznie jak powyżej
- x,y - signed int
    (x&~y) | ((x|~y) & (x-y))
    postępujemy analogicznie jak w a) rozważając przypadki

### Zadanie 7

:::success
Autor: Jakub Bok
:::
x - liczba ujemna, której wartość bezwzględną chcemy obliczyć
y = x>>31 - same 1 lub 0 w zależności czy liczba dodatnia czy ujemna
z = (x^y) - y

x^y (XOR) powoduje że w przypadku ujemnej liczby x, otrzymujemy w wyniku liczbę o 1 od niej mniejszą, 
po czym odejmujemy od niej y, czyli uprzednio stworzone -1 (same 1) - dodajemy 1
W przypadku dodatniej liczby w y, zapisywane są same 0, czyli liczba 0, natomiast po zastosowaniu XOR, 
dostaniemy dokładnie tą samą liczbę co na początku

alternatywnie:
```c=
int32_t abs(int32_t x)
{
    return (x^(x>>31)) - (x>>31);
}
```
Korzystamy z tego, że XORując liczbę ujemną dostaniemy jej wartość bezwzględną pomniejszoną o jeden.
Zatem gdy liczba x będzie ujemna to dostaniemy 1 w miejscach, gdzie wcześniej były zera, a w miejsce zer jedynki. Następnie odejmiemy - 1.
Z dodatnią nic nie zrobimy, bo x zostanie sXORowany z 0 i zmniejszony o 0.

```c=
((x>>31) & (-x)) + ((~x>>31) & x)

int mask = x>>31;
(mask & (-x)) + (~mask & x)
```

### Zadanie 8

:::success
Autor: Bartosz Sobocki
:::

Chcemy wydobyć znak liczby `x`. W ty celu stosujemy `x>>31`.  
Dla liczb ujemnych wynikiem jest `-1`. jednak dla liczb dodatnich wynikiem jest `0`.  
A zatem musimu użyć `-x>>31`, aby przekonać się, czy nie jest to przypadkiem liczba dodatnia (wynikiem będzie wtedy `-1`).  
Stosując `OR` mamy możliwość sprawdzenia, czy `x` jest liczbą niezerową, a wynikiem będzie przeciwny znak do pożądanego ze względu na minusy, a zatem trzeba odwrócić znak (minus przed wyrażeniem).


```cpp=

int sign(int32_t x){
    return -(-(x>>31)|(-x>>31));
}

int u_sign(uint32_t x){
    // używając uint32_t możemy wykonać tylko następujacą operację
    return (-x>>31);
}

```

### Zadanie 9

:::success
Autor: Marcin Szmagara
:::
Do rozwiązania zadania używamy poznanej na poprzednich zajęciach metody
dziel i zwyciężaj. Zauważamy, że wynik jest tożsamy z resztą z dzielenia
przez 2 liczby zapalonych bitów, a to jest to samo co and z 1:

```cpp=
/* Kiedy x zawiera nieparzystą liczbę jedynek zwróć 1, w p.p. 0 */
int32_t odd_ones(uint32_t x)
{
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
    return 1 & x;



    x = x ^ (x>>16);
    x = x ^ (x>>8);
    x = x ^ (x>>4);
    x = x ^ (x>>2);
    x = x ^ (x>>1);
    return x & 1;
}
```



## Porównanie rozwiązań (12:30 - 13:00)

:::info
Wszyscy studenci powinni zapoznać się z rozwiązaniami wszystkich zadań. Przy pomocy komentarzy do paragrafów można zgłaszać swoje wątpliwości lub uwagi. 
Mile widziane są alternatywne rozwiązania, które można zamieszczać poniżej za pomocą poniższego szablonu.
:::

### Zadanie X

:::success
Autor: 
:::

Zrobiłem to zupełnie inaczej...

## Prezentacja rozwiązań (13:00 - 14:00)

:::info
Ta część będzie polegała na zaprezentowaniu rozwiązań przez osoby, które je opracowały. Zadania będziemy prezentować po kolei. Osoba prezentująca będzie musiała opowiedzieć dlaczego rozwiązanie jest poprawne oraz odpowiedzieć na wszystkie ewentualne pytania od pozostałych studentów i prowadzącego.
:::

:::info
Podczas prezentacji prawdopodobnie będzie potrzebne współdzielenie ekranu przez prezentującego. Przydatne mogą być też takie narzędzia jak na przykład tablica: 
```awwapp.com```
:::x i c 