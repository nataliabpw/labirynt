# Labirynt — znajdowanie najkrótszej ścieżki

Program pozwala znaleźć najkrótszą ścieżkę od wejścia do wyjścia przez
wczytany z pliku labirynt.
Do rozwiązania problemu wykorzystano algorytm **BFS (Breadth-First Search)**.

Projekt został wykonany przez Natalię Biernacką i Antona Libika w ramach przedmiotu "Języki i metody programowania 2" realizowanego na Politechnice Warszawskiej.

---

## Funkcjonalności

- wczytywanie labiryntu z pliku tekstowego
- sprawdzanie poprawności danych wejściowych
- znajdowanie najkrótszej ścieżki przy użyciu BFS
- generowanie listy komend opisujących ruch w labiryncie

---

## Format pliku wejściowego

Labirynt musi być podany w postaci pliku tekstowego `TXT` lub binarnego `RLE8` o formie zgodnej z
przyjętymi oznaczeniami:
- P – punkt wejścia do labiryntu,
- K – punkt wyjścia z labiryntu,
- X – ściana,
- spacja – miejsce, po którym można się poruszać, czyli komórki labiryntu
i połączenia między nimi.

Wymagania:

- minimalny rozmiar labiryntu: **3 x 3**
- maksymalny rozmiar labiryntu: **1024 x 1024**
- punkt `P` i `K` muszą znajdować się przy krawędziach labiryntu

Przykład prawidłowego labiryntu o wymiarze 8 x 4:
```
XXXXXXXXXXXXXXXXX
X       X       X
X X XXX X XXXXX X
P X X   X   X   X
XXX X XXXXX X X X
X   X     X X X K
X XXXXXXXXX X X X
X           X X X
XXXXXXXXXXXXXXXXX
```
---

## Uruchomienie programu

Program uruchamia się z poziomu terminala:

```bash
labirynt [opcje] plik_wejsciowy
```

### Opcje

```
-f nazwa_pliku   zapis wyniku do pliku (brak tego parametru - stdout)
-h               wyświetlenie pomocy
```

### Przykład

```bash
./labirynt -f wynik.txt maze.txt
```

---

## Format wyjścia

Program wypisuje serię poleceń opisujących przejście przez labirynt.

Jako kierunek początkowy przyjęto poruszanie się w prawo.

Przykładowy fragment wyniku:

```
START
FORWARD 1
TURNLEFT
FORWARD 2
TURNRIGHT
FORWARD 3
STOP
```

---

## Algorytm

Do znalezienia najkrótszej ścieżki zastosowano algorytm **Breadth-First Search (BFS)**.


Dla każdego analizowanego węzła (pierwszego w **kolejce FIFO**):
- dodajemy do kolejki sąsiadów, czyli numery węzłów, które nie zostały
jeszcze odwiedzone i do których można przejść z aktualnie analizowanego
węzła,
- oznaczamy tych sąsiadów jako odwiedzonych,
- dla każdego sąsiada ustawiamy poprzednika jako analizowany węzeł,
- usuwamy analizowany węzeł z kolejki.

### Optymalizacje zastosowane w projekcie:

- przechowywanie informacji o odwiedzonych polach w formie **bitowej**
- zapis poprzedników przy użyciu **2 bitów na pole**

Dzięki temu program jest bardziej efektywny pamięciowo przy dużych labiryntach.

---

## Struktura projektu

Projekt jest podzielony na moduły:

```
main                          - główny moduł programu, punkt wejścia
checkparams                   - sprawdzanie parametrów wywołania
readmaze                      - wczytywanie i spawdzenie poprawności labiryntu
readfromtxt i readfromrle     - odczyt labiryntu z pliku (funkcje wywoływane w readmaze)
solvemaze                     - implementacja algorytmu BFS
printpath                     - generowanie i wypisywanie ścieżki
```

```
maze                          - struktura przechowująca labirynt
typedef struct {
FILE* input;
int inputtype;
int begin; //numer komórki początkowej
int end; //numer komórki końcowej
int columns;
int rows;
} maze;
```


```
path                          - struktury pomocnicze dla BFS
typedef struct {
FILE* input;
int inputtype;
int begin; //numer komórki początkowej
int end; //numer komórki końcowej
int columns;
int rows;
} maze;
```

---

## Autorzy

- Natalia Biernacka  
- Anton Libik

---

## Cel projektu

Celem projektu było:

- zaimplementowanie algorytmu grafowego w praktycznym problemie
- zaprojektowanie modularnej struktury programu
- obsługa błędów i walidacja danych wejściowych
- optymalizacja pamięci przy pracy na dużych danych

  
