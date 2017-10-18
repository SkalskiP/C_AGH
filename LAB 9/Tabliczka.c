#include <stdio.h>
#include <stdlib.h>

int *stworzWiersz(int pw, int kw) {
	/*pw - poczatek wiersza, kw - koniec wiersza*/
	
	int dlugosc = kw + 1 - pw;
	int *wiersz = (int*)malloc(dlugosc * sizeof(int));
	
	int index;
	for(index = pw; index <= kw; index++) {
		wiersz[index-pw] = kw*index;
	}
	/*for(index=0; index < dlugosc; index++) {
		printf("%d", wiersz[index]);
	}*/
	return 
	wiersz;
}

void odczytajWiersz(int* wiersz, int dlugosc) {
	
	int index;
	for(index = 0; index < dlugosc; index ++) {
		printf("%5d", wiersz[index]);
	}
}

void odczytajTabliczke(int** tabliczka, int xp, int xk) {
	
	printf("\n     |");
	int index;
	for(index = xp; index <= xk; index++) {
		printf("%5d", index);
	}
	printf("\n------");
	for(index = xp; index <= xk; index++) {
		printf("-----");
	}
	for (index = 0; index <= xk-xp; index++) {
		printf("\n%5d|", index+xp);
		odczytajWiersz(tabliczka[index], index+1);
	}
	
}

int main (void) {
	
	int xp, xk, dlugosc;
	
	printf("Podaj x poczatkowe: ");
	scanf("%d", &xp);
	printf("Podaj x koncowe: ");
	scanf("%d", &xk);
	
	dlugosc = xk + 1 - xp;
	
	int** tablica;
	tablica = (int**)malloc(dlugosc * sizeof(int*));
		
	int index, wiersz;
	for (index = 0, wiersz = xp; index < dlugosc; index++, wiersz++) {
		tablica[index] = stworzWiersz(xp, wiersz);		
	}

	odczytajTabliczke(tablica, xp, xk);
	
	return 0;
}
