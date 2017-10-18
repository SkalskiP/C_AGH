#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int ileLiter(char slowo[]) {

//Funkcja oblicza dlugosc slowa
	
	int index = 0;
	while (slowo[index] != 10) {
		index++;
	}
	return index;
}

int zrobBiblioteke(FILE *plik, double *tablica) {
	
	char buffor[50];
	int licznik = 0;
	
	while (!feof(plik)) {
        fgets(buffor, 50, plik);
    
        //if (licznik == 16 || licznik == 21 || licznik == 23) licznik++; //w jezyku polskim nie ma slow na q v x, wiec te numery licznika musza zostac sztucznie obrocone
        
        if (buffor[0] == (97 + licznik)) {
        	
        	double dlugoscSlowa = ileLiter(buffor);
        	
        	//printf("%s  ", buffor);
        	tablica[licznik] = ftell(plik) - dlugoscSlowa - 2.0;
        	        	
        	//printf("%d ", licznik);
        	
        	//printf("Pozycja w pliku: %.lf\n", tablica[licznik]);
        	
        	licznik++;
		}
        
	}
	
	tablica[26] = ftell(plik); //fgets przeszlo caly plik wiec wskaznik znajduje sie w ostatnim bajcie
	//printf("Pozycja w pliku: %.lf\n", tablica[26]);
	
	rewind(plik);
	return licznik;
}

losoweSlowo(FILE *plik, double *tablica, char litera, char *slowo) {
	
	int index = litera - 97;
	char buffor[50];
	
	//printf("%d", index);
	double lokalizacja = tablica[index] + (double)((rand()*10000) % (int)(tablica[index+1] - tablica[index]));
	//printf("%.lf\n", tablica[0]);
	//printf("%.lf\n", tablica[1]);	
	//printf("%.lf\n", lokalizacja);
	
	fseek(plik, lokalizacja, 0);
	fgets(buffor, 50, plik);
	fgets(buffor, 50, plik);
	//printf("%s", buffor);
	strcpy(slowo, buffor);
}


int main(void) {
	
	double bibliotekaPoczatki[27]; //w tej tablicy zostana zapisane lokalizacje pierwszych slow oraz ostatniego bajtu
	char rozwiazanie[50]; //w tej tablicy zapisane zostanie haslo
	
	
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
	
	int dlugoscRozwiazania = ileLiter(rozwiazanie);
	
	zrobBiblioteke(file, bibliotekaPoczatki);
	
	int index;
	for(index = 0; index < dlugoscRozwiazania; index++) {
		char slowo[50];
		losoweSlowo(file, bibliotekaPoczatki, rozwiazanie[index], slowo);
		drukujHaslo(slowo);
	}	
		
	/*fseek(file, -10, 2);
	long offset = ftell(file);
	printf("Pozycja w pliku: %d\n", offset);*/	
    
    /*fseek(file, 15267358, 0);
    char buffor[50];
    fgets(buffor, 50, file);
    printf("%s  ", buffor);*/
    
	fclose(file);	
	return 0;
}
