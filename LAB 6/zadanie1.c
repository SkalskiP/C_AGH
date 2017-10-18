#include <stdio.h>

int main (void) {
	
	//Definiowanie zmiennych typu int
	int a = 3, b = 5, x;
	//Definiowanie wskaŸników typu int
	int *point_a, *point_b;
	
	//Zmienne typi int przypisujemy do zmiennych wskaŸnikowych za pomoc¹ operatorów adresu, które tworz¹ wskaŸniki 
	point_a = &a;
	point_b = &b;
	
	//Aby odwo³aæ siê do wartoœci zmiennych za poœrednictwem adresów, u¿ywamy operatorów wy³uskania
	x = *point_a + *point_b;
	printf("%d", x); 
	
	return 0;
}
