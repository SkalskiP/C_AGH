#include <stdio.h>

int main(int argc, char *argv[]) {

int xpoczatek, xkoniec, ypoczatek, ykoniec;

printf("Podaj poczatek i koniec pierwszego zakresu: ");
scanf("%d %d", &xpoczatek, &xkoniec);

printf("Podaj poczatek i koniec drugiego zakresu: ");
scanf("%d %d", &ypoczatek, &ykoniec);

printf("\n\n");

int i, j;
for(i = xpoczatek; i <= xkoniec; i++ ) {
    for(j = ypoczatek; j <= ykoniec; j++ ) {
        printf("%5d", i*j);
    }
    printf("\n");
}

return 0;
}
