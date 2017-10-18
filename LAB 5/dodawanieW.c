#include <stdio.h>

void pobieranieWetorac (int *wektor, int dlugosc) {
	
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

void dodawanie (int *wektor1, int *wektor2, int *wynik, int dlugosc) {
	int index;
	for (index = 0; index < dlugosc; index ++) {
		wynik[index] = wektor1[index] + wektor2[index];
	}
}

int main(void) {
	int l;
	printf("Wprowadz dlugosc wektora. ");
	scanf("%d", &l);
	int vector1[l], vector2[l], wynik[l];

	pobieranieWetorac(&vector1[0], l);
	pobieranieWetorac(&vector2[0], l);
	
	dodawanie (&vector1[0], &vector2[0], &wynik[0], l);

	int index1; 
	for(index1 = 0; index1 < l; index1++) {
		printf("%d ", wynik[index1]);
	}
	
	return 0;
}
