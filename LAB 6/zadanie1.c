#include <stdio.h>

int main (void) {
	
	//Definiowanie zmiennych typu int
	int a = 3, b = 5, x;
	//Definiowanie wska�nik�w typu int
	int *point_a, *point_b;
	
	//Zmienne typi int przypisujemy do zmiennych wska�nikowych za pomoc� operator�w adresu, kt�re tworz� wska�niki 
	point_a = &a;
	point_b = &b;
	
	//Aby odwo�a� si� do warto�ci zmiennych za po�rednictwem adres�w, u�ywamy operator�w wy�uskania
	x = *point_a + *point_b;
	printf("%d", x); 
	
	return 0;
}
