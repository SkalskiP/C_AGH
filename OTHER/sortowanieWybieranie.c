#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* zbudujListe(int wielkosc) {
	
	int* lista = (int *)malloc(wielkosc*sizeof(int));
	
	int index;
	for (index = 0; index < wielkosc; index ++) {
		
		lista[index] = rand() % 1000;
		
	}
	
	return lista;
	
}

void drukujListe(int* lista, int wielkosc) {
	
	int index;
	printf("[");
	for (index = 0; index < wielkosc - 1; index++) {
		printf("%d, ", lista[index]);
		
	}
	printf("%d]", lista[wielkosc-1]);
}

int maksymalnaWartosc(int* lista, int poczatek, int koniec) {
	
	int index, indexMaximum = 0, maksimum = lista[poczatek];
	for (index = poczatek +1; index <= koniec; index ++) {
		if (lista[index] > maksimum) {
			maksimum = lista[index];
			indexMaximum = index;
		}
	}
	return indexMaximum;
}

void sortowanieWybor(int* lista, int wielkosc) {
	
	int index;
	for(index = wielkosc-1; index >= 0; index--) {
		int maximumIndex = maksymalnaWartosc(lista, 0, index);
		//printf("%d\n", lista[maximumIndex]);
		if (lista[maximumIndex] > lista[index]) {
			int tmp = lista[maximumIndex];
			lista[maximumIndex] = lista[index];
			lista[index] = tmp;
		}
	}
		
}

int main(void) {
	
	srand(time(NULL));
	int wielkosc;
	printf("Podaj wielkosc sortowanej listy: ");
	scanf("%d", &wielkosc);
	
	int* lista = zbudujListe(wielkosc);
	//printf("%d", lista[5]);	
	drukujListe(lista, wielkosc);
	
	//int indexMaksimum = maksymalnaWartosc(lista, 0, 0);
	//printf("\nMaksimum ze zbioru wynosi: %d.", lista[indexMaksimum]);
	sortowanieWybor(lista, wielkosc);
	printf("\n");
	drukujListe(lista, wielkosc);
	
	return 0;
}
