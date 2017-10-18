#include <stdio.h>
int czas(int x, int y, int *ilosc, int *reszta){
    *ilosc = (int) x/y;
    *reszta = x%y;
}

int main(void)
{
    int wynik[5];
    int podzial[] = {60,60,24,7};

    printf("Podaj liczbe sekund:\n");
    scanf("%d", &wynik[0]);

    int i;
    for(i = 0; i < 4; i++){
        czas(wynik[i], podzial[i], &wynik[i+1], &wynik[i]);
    }

    printf("Podana liczba sekund to:\n");
    printf("%d tygodni\n", wynik[4]);
    printf("%d dni\n", wynik[3]);
    printf("%d godzin\n", wynik[2]);
    printf("%d minut\n", wynik[1]);
    printf("%d sekund\n", wynik[0]);
}
