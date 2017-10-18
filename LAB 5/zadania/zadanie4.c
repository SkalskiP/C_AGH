#include <stdio.h>
#include <math.h>

void pobieranieWetorac (float *wektor, int dlugosc);
float len (float *wektor1, int dlugosc);

int main(void) {
	int l;
	printf("Wprowadz ilosc wspolrzednych wektora: ");
	scanf("%d", &l);
	float vector1[l];
	float wynik;

	pobieranieWetorac(&vector1[0], l);
	
	wynik = pow(len(&vector1[0], l), 0.5);
	printf("%f", wynik);
	return 0;
}

void pobieranieWetorac (float *wektor, int dlugosc) {
	
	printf("Wprowadz elementy wektora, oddzielajac je spacjami:\n");
	
	int index;
	for(index = 0; index < dlugosc; index++) {
		int tmp;
		
		if (index != dlugosc-1) {
			scanf("%d ", &tmp);
		}
		else scanf("%d", &tmp);
		
		wektor[index] = tmp;
	}		
}

float len (float *wektor1, int dlugosc) {
	float wynik = 0;
	int index;
	for (index = 0; index < dlugosc; index ++) {
		wynik = wynik + wektor1[index]*wektor1[index];
	}
	return(wynik);
}

