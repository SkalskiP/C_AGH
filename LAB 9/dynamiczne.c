#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

int main (void) {
	
	char buffor[50];
	int dlugosc;
	
	printf("Podaj lancuch znakow: \n");
	fgets(buffor, MAX, stdin);
	
	dlugosc = strlen(buffor);
	
	/* malloc zwraca wskaznik void*, ktory potem musimy zrzutowc na wskaznik typu ktory potrzebujemy agument to wielkosc pamieci jakiej potrzebujemy*/
	char *tekst = (char*) malloc(dlugosc*sizeof(char));
	
	if (tekst != NULL) {
		strcpy(tekst, buffor);	
		int dlugosc2 = strlen(tekst);	
		printf("Dlugosc slowa: %d", dlugosc2);
	}
	
	else {
		printf("Przydzielanie pamieci nieudane!");
	}
	
	free(tekst);
	
	return 0;
}
