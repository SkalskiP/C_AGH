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

double delta(void){
    int wybor;

    while (wybor != 1 || wybor != 2 || wybor != 3 || wybor != 4 || wybor != 5){
        system("cls");
        printf("\n\tWYBIERZ WIELKOSC WSPOLCZYNNIKA DELTA");
        printf("\n\t------------------------------------");
        printf("\n\t 1. 1");
        printf("\n\n\t 2. 0.1");
        printf("\n\n\t 3. 0.01");
        printf("\n\n\t 4. 0.001");
        printf("\n\n\t 5. 0.0001");
        printf("\n\t------------------------------------");
        printf("\n\t WYBIERASZ: ");
        scanf("%d",&wybor);
        switch(wybor){
        case 1:
              return 1;
        case 2:
              return 0.1;
        case 3:
              return 0.01;
        case 4:
              return 0.001;
        case 5:
              return 0.0001;
        default:
              printf("\n\tNIEPOPRAWNY WYBOR. SPROBOJ PONOWNIE.");
        }
        (void)getch();
    }
}

int main(void){
    double x, y, dx;
    printf("Wprowadz wartosc x, dla ktorej chcesz obliczyc pochodna: ");
    scanf("%lf", &x);
    dx = delta();
    y = diff(x, dx);
    printf("\n\tWARTOSC POCHODNEJ JEST ROWNA: %f", y);

}


