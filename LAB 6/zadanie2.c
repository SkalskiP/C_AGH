#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void funkcja(double a, double b, double *modul, double *argument);

int main (void) {
	
	double a = 3, b = 4, modul, argument; 
	
	funkcja(a, b, &modul, &argument);
	printf("Modul liczby zespolonej jest rowny: %lf.\n", modul);
	printf("Zas jej argument wynosi %lf.", argument);
	
	return 0;
}

void funkcja(double a, double b, double *modul, double *argument) {
	
	*modul = pow((a*a + b*b) , 0.5);
	*argument = (atan(b/a)*180)/PI;
	
}
