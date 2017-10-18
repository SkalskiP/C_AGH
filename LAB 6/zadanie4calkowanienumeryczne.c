#include <stdio.h>
#include <math.h>

double wartoscf(double argument);
double Simpson (double poczatek, double koniec);
double calkaNum(double poczatek, double koniec, double delta);

int main (void) {
	
	double a, b, S;
	double delta;
	
	printf("Podaj poczatek przedzialu calkowania: ");
	scanf("%lf", &a);
	printf("Podaj koniec przedzialu calkowania: ");
	scanf("%lf", &b);
	printf("Podaj wymagana dokladnosc [delta]: ");
	scanf("%lf", &delta);
	
	S = calkaNum(a, b, delta);
	
	printf("%lf\n", S);
	
	return 0;
}

double wartoscf(double argument) {
	
	double wynik = pow(argument, 5) + 8*pow(argument,3) + 4*pow(argument,2) + argument + 5;
	return wynik;	
}

double Simpson (double poczatek, double koniec) {
	
	double h, S;
	h = koniec - poczatek;
	S = h*(wartoscf(poczatek) + 4*wartoscf(poczatek/2 + koniec/2) + wartoscf(koniec))/6;
	return S;
}

double calkaNum(double poczatek, double koniec, double delta) {
	double c, S, S1, S2;
	c = (poczatek + koniec)/2;
	
	S = Simpson(poczatek, koniec);
	//printf("%lf  ", S);
	S1 = Simpson(poczatek, c);
	S2 = Simpson(c, koniec);
	//printf("%lf  ", (S1+S2));
	//printf("%lf  ", fabs(S - (S1+S2)));
	
	if ( fabs(S - (S1+S2)) <= delta) return S;
	else return (calkaNum(poczatek, c, delta/2) + calkaNum(c, koniec, delta/2));
	
}
