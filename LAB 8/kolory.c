#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *wczytaj(char *z, int ile);
enum widmo {czerwony, pomaranczowy, zolty, zielony, niebieski, fioletowy};
const char * kolory[] = {"czerwony", "pomaranczowy", "zolty", "zielony", "zielony", "niebieski", "fioletowy"};

#define DLUGOSC 30

int main(void) {
	
	char wybor[DLUGOSC];
	enum widmo kolor;
	bool kolor_znaleziony = false;
	puts("Podaj kolor:");
	
	while(wczytaj(wybor, DLUGOSC) != NULL && wybor[0] != '\0')
	{
		for (kolor = czerwony; kolor <= fioletowy; kolor++) {
			
			if (strcmp(wybor, kolory[kolor]) == 0) {
				
				kolor_znaleziony = true;
				break;
				
			}
			
		}
		
		if (kolor_znaleziony)
			switch(kolor) {
			
				case czerwony: 
					puts("Roze sa czerwone.");
					break;
				case pomaranczowy:
					puts("Maki sa pomaranczowe.");
					break;
				case zolty:
					puts("Sloneczniki sa zolte.");
					break;
				case zielony:
					puts("Trawa jest zielona.");
					break;
				case niebieski:
					puts("Dzwonki sa niebieskie.");
					break;	
				case fioletowy:
					puts("Fiolki sa fioletowe.");
					break;												
			}
		else
			printf("Nie wiem nic o kolorze %s.\n", wybor);
		kolor_znaleziony = false;
		printf("Podaj nastepny kolor:");
	}
	puts("Do widzenia!");
	
	return 0;
}

char *wczytaj(char *zmienna, int dlugosc) {
	char *wynik;
	char *tutaj; //lokalizacja znaku enter
	wynik = fgets(zmienna, dlugosc, stdin);
	if (wynik) {
		//funkcja strchr lokalizuje pierwsze wystapienie danego znaku w striingu
		tutaj = strchr(zmienna, '\n'); //szukamy znaku nowego wiersza
		if (tutaj) //jesli adres jest rozny od NULL
			*tutaj = '\0'; //zamienia znak nowego wiersza na pusty
		else
			while (getchar() != '\n')
				continue;
	}
	return wynik;
}
