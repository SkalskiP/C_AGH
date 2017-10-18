#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ileLiter(char slowo[]) {
	
	int index = 0;
	while (slowo[index] != 10) {
		index++;
	}
	return index;
}

int ileWierszy(FILE *plik) {
	
	char buffor[50];
	int licznik = 0;
	
	while (!feof(plik)) {
        fgets(buffor, 50, plik);
        licznik++;
	}
	
	rewind(plik);
	return licznik;
}

int wyszukaj(FILE *plik, int poczatek, int koniec, char litera, char *slowo) {
	
	rewind(plik);
	int delta = poczatek - koniec;
	int wiersz = (poczatek + koniec)/2 + ((rand() % delta/3)-delta/6);
	//printf("%d ", wiersz);
	char buffor[50];
	int licznik = 1;
	
	while (!feof(plik) && (licznik <= wiersz)) {
        fgets(buffor, 50, plik);
    
        if (licznik == wiersz) break;
        licznik++;
	}
	
	if (buffor[0] == litera) {
		strcpy(slowo, buffor);
		//printf("%s", buffor);
		return 1;
	}
	else if (buffor[0] > litera) {
		return wyszukaj(plik, poczatek, wiersz, litera, slowo);
	}
	else if (buffor[0] < litera) {
		return wyszukaj(plik, wiersz, koniec, litera, slowo);
	}

}

void drukujHaslo (char haslo[]) {
	
	int dlugoscHasla = ileLiter(haslo);
	
	int index;
	for (index = 0; index < dlugoscHasla; index++) {
		
		if (index == 0) {
			printf("|%c| ", haslo[index] - 32);
		}
		else {
			printf("%c ", haslo[index]);
		}
		
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	char rozwiazanie[50];
	int dlugoscRozwiazania;
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\nowyslownik.txt", "r");
	srand(time(NULL));
	
	
	if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    
    printf("Podaj slowo, ktore ma stanowic rozwiazanie krzyzowki: ");
    fgets(rozwiazanie, (sizeof(rozwiazanie)/(sizeof(rozwiazanie[0])) - 1), stdin);
	
	system("cls");
	
    dlugoscRozwiazania = ileLiter(rozwiazanie);
	int wiersze = ileWierszy(file);
	//printf("%d\n", wiersze);

	int index;
	for(index = 0; index < dlugoscRozwiazania; index++) {
		char slowo[50];
		wyszukaj(file, 1, wiersze, rozwiazanie[index], slowo);
		drukujHaslo(slowo);
	}
    
}
