#include <stdio.h>
#include <math.h>
#include <windows.h>

double funkcja(double zmienna){
/* funkcja oczekuje wprowadzenia zmiennej w typie double
 zwraca wartoœæ kwadratu wprowadzonej zmiennej*/
    return pow(zmienna,2);
}

double diff(double x, double dx){
/* funkcja zwraca wartosc ilorazu roznicowego dla zadanego x oraz dx */
    return (funkcja(x+dx)-funkcja(x))/dx;
}

int main(void){
    double x, y, dx;
    x = 1;
    dx = 1;

    int i;
    for(i = 0; i < 16; i++){
        y = diff(x, dx) - 2*x;
        printf("%.16lf\n", y);
        dx = dx/10;
    }
}
