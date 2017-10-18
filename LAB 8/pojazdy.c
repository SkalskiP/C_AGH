#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 31

enum widmo {czerwony, pomaranczowy, zolty, zielony, niebieski, fioletowy};
const char * kolory[] = {"czerwony", "pomaranczowy", "zolty", "zielony", "zielony", "niebieski", "fioletowy"};

struct osobowy {
	char marka[MAX];
	char naped[MAX];
	int drzwi;
	int kolor;
	double cena;
	char daty[10][11];
};

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

const char * odczytajKolor (enum widmo kolor) {
	
	switch(kolor)
	{
		case czerwony: return "czerwony";
		case pomaranczowy: return "pomaranczowy";
		case zolty: return "zolty";
		case zielony: return "zielony";
		case niebieski: return "niebieski";
		case fioletowy: return "fioletowy";
	}
}

int main(void) {
	
	struct osobowy pojazd1;
	
	char wybranyKolor[MAX];
	enum widmo kolor;
	bool kolor_znaleziony = false;
		
	printf("Podaj marke pojazdu.\n");
	wczytaj(pojazd1.marka, MAX);
	printf("Podaj naped pojazdu.\n");
	wczytaj(pojazd1.naped, MAX);
	printf("Podaj ilosc drzwi.\n");
	scanf("%d", &pojazd1.drzwi);
	printf("Podaj kolor pojazdu.\n");
	
	fseek(stdin,0,SEEK_END);

	while (kolor_znaleziony == false)
	{
		wczytaj(wybranyKolor, MAX);
		
		for (kolor = czerwony; kolor <= fioletowy; kolor++) {
			if (strcmp(wybranyKolor, kolory[kolor]) == 0)
			{
				kolor_znaleziony = true;
				break;
			}
		}
		
		if (kolor_znaleziony) 
		
			switch(kolor)
			{
				case czerwony:
					pojazd1.kolor = czerwony;
					break;
				case pomaranczowy:
					pojazd1.kolor = pomaranczowy;
					break;
				case zolty:
					pojazd1.kolor = zolty;
					break;
				case zielony:
					pojazd1.kolor = zielony;
					break;
				case niebieski:
					pojazd1.kolor = niebieski;
					break;
				case fioletowy:
					pojazd1.kolor = fioletowy;
					break;		
			}
		
		else
			printf("Nie wiem nic o kolorze %s.\n", wybranyKolor);

	}

	printf("Podaj cene pojazdu.\n");
	scanf("%lf", &pojazd1.cena);
	
	printf("marka: %s, naped: %s, ilosc drzwi: %d, kolor: %s, cena: %.2lf EURO \n", pojazd1.marka, pojazd1.naped, pojazd1.drzwi, odczytajKolor(pojazd1.kolor), pojazd1.cena);
	printf("GOTOWE");
	
	return 0;
}
