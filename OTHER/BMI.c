#include <stdio.h>
#include <math.h>

int BMI(double masa, double wzrost, double *wynik){
    *wynik = masa/(pow(wzrost,2));
}


int main(void)
{
    double masa, wzrost, wynik;
    printf("Podaj mase [kg]:\n");
    scanf("%lf", &masa);
    printf("Podaj wzrost [m]:\n");
    scanf("%lf", &wzrost);


    BMI(masa, wzrost, &wynik);
    printf("%.2lf", wynik);
}
