#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int podstawa, wynik;
    char liczba[32];

    printf("Wprowadz podstawe systemu: ");
    scanf("%d", &podstawa);

    printf("Wprowadz wartosc liczby w wybranym systemie liczbowym: ");
    fgets(liczba, 31, stdin);

    printf("%ld", sizeof liczba);



	return 0;
}
