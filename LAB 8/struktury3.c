#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 31

enum widmo {czerwony, pomaranczowy, zolty, zielony, niebieski, fioletowy, czarny, bialy};
const char * kolory[] = {"czerwony", "pomaranczowy", "zolty", "zielony", "zielony", "niebieski", "fioletowy", "czarny", "bialy"};

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
		case czarny: return "czarny";
		case bialy: return "bialy";
	}
}

struct pojazd {
		
	char marka[MAX];
	char naped[MAX];
	int kolor;
	double cena;
	int key;
	char datyPrzegladu[3][MAX]; //ZMIANA MA WPLYW NA FUNKCJE POBIERAJACE I DRUKUJACE DANE 
		
	union typ {
		
		struct osobowy {
		    	
			int drzwi;
		} osobowy;
		
		struct ciezarowy {
		    	
			double ladownosc;
		    double dlugosc;			
		} ciezarowy;
		    
		struct autobus {
		    	
		    int ilosc_miejsc;
		    double dlugosc;
		} autobus;
		
	} typ;
};

int zapiszKolor (void) {
	
	int kolorAuta;
	char wybranyKolor[MAX];
	bool kolor_znaleziony = false;
	enum widmo kolor;
	
	while (kolor_znaleziony == false)
	{
		wczytaj(wybranyKolor, MAX);
		
		for (kolor = czerwony; kolor <= bialy; kolor++) {
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
					kolorAuta = czerwony;
					break;
				case pomaranczowy:
					kolorAuta = pomaranczowy;
					break;
				case zolty:
					kolorAuta = zolty;
					break;
				case zielony:
					kolorAuta = zielony;
					break;
				case niebieski:
					kolorAuta = niebieski;
					break;
				case fioletowy:
					kolorAuta = fioletowy;
					break;
				case czarny:
					kolorAuta = czarny;
					break;
				case bialy:
					kolorAuta = bialy;
					break;		
			}
		
		else
			printf("Nie wiem nic o kolorze %s.\n", wybranyKolor);
	}
		
}

void danePodstawowe (struct pojazd *egzemplarz) {
	
	fseek(stdin,0,SEEK_END);
	
	printf("\nPodaj marke pojazdu: \n");
	wczytaj((*egzemplarz).marka, MAX);
	printf("Podaj naped pojazdu: \n");
	wczytaj((*egzemplarz).naped, MAX);
	printf("Podaj kolor pojazdu: \n");
	(*egzemplarz).kolor = zapiszKolor();
	printf("Podaj cene pojazdu.\n");
	scanf("%lf", &(*egzemplarz).cena);
	
	int index; //WAZNE FUNKCJA ZALEZY OD ILOSCI DAT PRZEGLADU
	for (index = 0; index < 3; index ++) {
		printf("Podaj date %d przegladu:\n", index + 1);
		
		fseek(stdin,0,SEEK_END);
		
		wczytaj((*egzemplarz).datyPrzegladu[index], MAX);
	}
		
}

void daneSzczegolowe (struct pojazd *egzemplarz) {
	
	switch((*egzemplarz).key)
	{
		case 1:
			printf("Podaj ilosc drzwi: \n");
			scanf("%d", &(*egzemplarz).typ.osobowy.drzwi);
			break;
		case 2:
			printf("Podaj ladownosc: \n");
			scanf("%lf", &(*egzemplarz).typ.ciezarowy.ladownosc);
			printf("Podaj dlugosc: \n");
			scanf("%lf", &(*egzemplarz).typ.ciezarowy.dlugosc);
			break;
		case 3:
			printf("Podaj ilosc miejsc siedzacych: \n");
			scanf("%d", &(*egzemplarz).typ.autobus.ilosc_miejsc);
			printf("Podaj dlugosc: \n");
			scanf("%lf", &(*egzemplarz).typ.autobus.dlugosc);
			break;
	}
	
}

void drukujDane(struct pojazd egzemplarz) {
	
	system("cls");
	printf("\nmarka: %s\n", egzemplarz.marka);
	printf("-------------------------------\n");
	printf("naped: %s\n", egzemplarz.naped);
	printf("kolor: %s\n", odczytajKolor(egzemplarz.kolor));
	printf("cena: %.2lf EURO\n", egzemplarz.cena);
	
	switch(egzemplarz.key)
	{
		case 1:
			printf("ilosc drzwi: %d\n", egzemplarz.typ.osobowy.drzwi);
			break;
		case 2:
			printf("ladownosc: %.2lf t\n", egzemplarz.typ.ciezarowy.ladownosc);
			printf("dlugosc: %.2lf m\n", egzemplarz.typ.ciezarowy.dlugosc);
			break;
		case 3:
			printf("ilosc miejsc: %d\n", egzemplarz.typ.autobus.ilosc_miejsc);
			printf("dlugosc: %.2lf m\n", egzemplarz.typ.autobus.dlugosc);
			break;
	}
	
	printf("\nZapisane terminy przegladow:\n");
	
	int index;
	for (index = 0; index < 3; index++) { //WAZNE FUNKCJA ZALEZY OD ILOSCI DAT PRZEGLADU
		
		printf("Termin %d przegladu: %s\n", index +1, egzemplarz.datyPrzegladu[index]);
	}
	
	getch();	
}

int main (void) {
	
	int iloscPojazdow;
	printf("Podaj ilosc wprowadzanych pojazdow: ");
	scanf("%d", &iloscPojazdow);
		
	struct pojazd tablica[iloscPojazdow];
	
	int index;
	for(index = 0; index < iloscPojazdow; index++) {
		
		system("cls");
		
		printf("Podaj typ pojazdu\n\n1 - auto osobowe\n2 - auto ciezrowe\n3 - autobus\n\nTwoj wybor: ");
		scanf("%d", &tablica[index].key);
	
		danePodstawowe(tablica + index);
		daneSzczegolowe(tablica + index);
		
	}

	
	for(index = 0; index < iloscPojazdow; index++) {
		
		drukujDane(tablica[index]);
		
	}
			
	return 0;	
	
}


