#include <stdio.h>

void pobieranieWetorac (int wektor[], int dlugosc) {
	
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

int sumowanie (int wektor[], int dlugosc) {
	
	int index;
	int suma = 0;
	for(index = 0; index < dlugosc; index++) {
		suma = suma + wektor[index];
	}
	
	return suma;
}

int main(void) {
	int l, suma;
	printf("Wprowadz dlugosc wektora. ");
	scanf("%d", &l);
	int vector1[l];

	pobieranieWetorac(vector1, l);

	suma = sumowanie(vector1, l);
	printf("%d", suma);
	
	return 0;
}
