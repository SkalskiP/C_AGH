#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* zbudujTablice(wielkosc) {
	
	int* lista = (int*)malloc(wielkosc*sizeof(int));
	
	int index;
	for(index = 0; index < wielkosc; index++) {
		lista[index] = rand() % 100;
	}
	
	return lista;
}

void drukujListe(int* lista, int wielkosc) {
	
	int index;
	
	printf("[");
	for (index = 0; index < wielkosc-1; index++) {
		printf("%d, ", lista[index]);
	}
	printf("%d]", lista[wielkosc-1]);
}

void szybkiSort(int* lista, int poczatek, int koniec) {
	
	if (poczatek < koniec) {
		int pivot = lista[koniec];
		int pivotIndex = koniec;
		int frontIndex = poczatek;
		
		int index;
		for (index = poczatek; index <= koniec; index++) {
			if (lista[index] <= lista[pivotIndex]) {
				int tmp = lista[index];
				lista[index] = lista[frontIndex];
				lista[frontIndex] = tmp;
				frontIndex ++;
			}
		}
		
		szybkiSort(lista, poczatek, frontIndex-2);
		szybkiSort(lista, frontIndex, koniec);
	}
}

int main (void) {
	
	srand(time(NULL));
	
	int wielkosc;
	int* tablica;
	printf("Podaj ilosc losowych liczb w zbiorze: ");
	scanf("%d", &wielkosc);
	
	tablica = zbudujTablice(wielkosc);
	drukujListe(tablica, wielkosc);
	szybkiSort(tablica, 0, wielkosc-1);
	printf("\n");
	drukujListe(tablica, wielkosc);
	return 0;
}
