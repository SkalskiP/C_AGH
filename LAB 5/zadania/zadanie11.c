#include<stdio.h>

void pobieranieTablicy (float *wektor, int dlugosc) {
	
	printf("Wprowadz elementy tablicy, oddzielajac je spacjami:\n");
	
	int index;
	for(index = 0; index < dlugosc; index++) {
		
		float tmp;
		
		if (index != dlugosc-1) {
			scanf("%f ", &tmp);
		}
		else scanf("%f", &tmp);
		
		wektor[index] = tmp;
	}		
}

int main (void) {
	
	int x, index_x, index_wew;
	printf("Wprowadz dlugosc tablicy: ");
	scanf("%d ", &x);
	
	float tablica[x];
	pobieranieTablicy(&tablica[0], x);
	
	
	for (index_x = x-1; index_x >= 1; index_x--) {
		
		for (index_wew = 1; index_wew <= index_x; index_wew++) {
			
			if ( tablica[index_wew] < tablica[index_wew - 1]) {
				
				float tmp = tablica[index_wew - 1];
				tablica[index_wew - 1] = tablica[index_wew];
				tablica[index_wew] = tmp;
				
			}
			
		} 
		
	}
	
	for(index_x = 0; index_x < x; index_x++) {
		printf("%.3f ", tablica[index_x]);
	}
	
	return 0;
}
