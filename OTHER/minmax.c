#include <stdio.h>
#include <time.h>

void tworzenieTablicy(int wielkosc, int tablica[]) {
	
	int index;
	for (index = 0; index < wielkosc; index++) {
		tablica[index] = (rand() % 1000);
	}
	
}

void drukowanieTablicy(int wielkosc, int tablica[]) {
	
	int index;
	
	printf("Twoja tablica to:");
	
	for (index = 0; index < wielkosc; index++) {
		printf("%d ", tablica[index]);
	}
	printf("\n\n");
}

void minmax(int wielkosc, int tablica[], int *min, int * max) {
	
	int index; 
	*min = tablica[0];
	*max = tablica[0];
	
	for(index = 1; index < wielkosc; index++) {
		
		if (tablica[index] > *max) {
			*max = tablica[index];
		}
		
		if (tablica[index] < *min) {
			*min = tablica[index];
		}
	}
	
	//*min = MIN;
	//*max = MAX;
}

int main (void) {
	
	srand ( time(NULL) );
	
	int wielkosc = 10, tablica[wielkosc];
	
	int min, max;
	
	tworzenieTablicy(wielkosc, tablica);
	drukowanieTablicy(wielkosc, tablica);
	
	minmax(wielkosc, tablica, &min, &max);
	
	printf("Wartosc minimalna to: %d\n", min);
	printf("Wartosc maksymalna to: %d", max);
	
	return 0;
}
