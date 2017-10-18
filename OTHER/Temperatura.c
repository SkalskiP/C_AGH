#include <stdio.h>

int Conv(int Celsjusz, double *Fahrenheit){
    *Fahrenheit = 1.8*Celsjusz+32;
}


int main(void)
{
    int stopnie;
    double wynik;
    printf("Podaj temperature w stopniach Celsujsza:\n");
    scanf("%d", &stopnie);

    Conv(stopnie, &wynik);
    printf("%f",wynik);
}
