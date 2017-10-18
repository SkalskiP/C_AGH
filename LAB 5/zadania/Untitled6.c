#include <stdio.h>

int main (void) {
	int x, y;
	int max_x, max_y;
	double maximum = -100000000000;
	
	printf("Wprowadz ilosc wierszy macierzy: ");
	scanf("%d", &y);
	printf("Wprowadz ilosc kolumn macierzy: ");
	scanf("%d", &x);
	
	double macierz[y][x];
	
	int index_y;
	int index_x;
	
	for	(index_y = 0; index_y < y; index_y++){
		
		printf("Wprowadz elementy wiersza %d, oddzielajac je spacjami:\n", index_y+1);
		
		for (index_x = 0; index_x < x; index_x++) {
			
			double tmp;
			
			if (index_x != x-1) {
				scanf("%lf ", &tmp);
			}
			else scanf("%lf", &tmp);
			
			macierz[index_y][index_x] = tmp;		
		}	
	}
	
	for (index_y = 0; index_y < y; index_y++) {
		
		for (index_x = 0; index_x < x; index_x++) {
			
			if (macierz[index_y][index_x] > maximum) {
				maximum = macierz[index_y][index_x];
				max_x = index_x+1;
				max_y = index_y+1;
			}
		}
	}
	
	printf("Najwieksza wartosc zapisana w macierzy jest rowna %4lf. Znajduje sie w %d wieszu i %d kolumnie", maximum, max_y, max_x);
	
	return 0;
}
