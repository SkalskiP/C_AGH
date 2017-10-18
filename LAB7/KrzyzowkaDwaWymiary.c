#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void drukujHaslo (char *poziomoG, char *poziomoD, char *pionowoL, char *pionowoP, int poziomo, int pionowo) {
	
	printf("\n\t%s", poziomoG);
	
	int index;
	for (index = 0; index < pionowo -2; index++) {
		
		int index2;
		for (index2 = 0; index2 < poziomo; index2++) {
			
			if (index2 == 0) {
				printf("\t%c", pionowoL[index+1]);
			}
			else if (index2 == (poziomo -1)) {
				printf("%c\n", pionowoP[index+1]);
			}
			else printf(" ");
			
		}
		
	}
	
	printf("\t%s", poziomoD);

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
        	
        	tablica[licznik] = ftell(plik) - dlugoscSlowa - 2.0;
        	
        	licznik++;
		}
        
	}
	
	tablica[26] = ftell(plik); //fgets przeszlo caly plik wiec wskaznik znajduje sie w ostatnim bajcie
	
	rewind(plik);
	return licznik;
}

void losoweSlowo(FILE *plik, double *tablica, char litera, char *slowo) {
	
	int index = litera - 97;
	char buffor[50];

	double lokalizacja = tablica[index] + (double)((rand()*10000) % (int)(tablica[index+1] - tablica[index]));

	fseek(plik, lokalizacja, 0);
	fgets(buffor, 50, plik);
	fgets(buffor, 50, plik);
	strcpy(slowo, buffor);
}


int main(void) {
	
	double bibliotekaPoczatki[27]; //w tej tablicy zostana zapisane lokalizacje pierwszych slow oraz ostatniego bajtu
	char klucz;
	char poziomoG[50], poziomoD[50], pionowoP[50], pionowoL[50];
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\nowyslownik.txt", "r");
	srand(time(NULL));	
	
	if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    
    printf("Podaj litere rozpoczynajaca krzyzowke: ");
    scanf("%c", &klucz);
	
	system("cls");
	
	zrobBiblioteke(file, bibliotekaPoczatki);
	
	int flaga = 0;
	
	int dlugoscPoziomoG, dlugoscPionowoL;
	
	
	while(flaga == 0) {
	
	flaga = 1;
	
	losoweSlowo(file, bibliotekaPoczatki, klucz, poziomoG);
	dlugoscPoziomoG = ileLiter(poziomoG);
	//printf("%s ", poziomoG);
	losoweSlowo(file, bibliotekaPoczatki, klucz, pionowoL);	
	dlugoscPionowoL = ileLiter(pionowoL);
	//printf("%s ", pionowoL);
	
	int dlugoscPoziomoD = 0;
	while (dlugoscPoziomoD != dlugoscPoziomoG) {
		losoweSlowo(file, bibliotekaPoczatki, pionowoL[dlugoscPionowoL-1], poziomoD);
		dlugoscPoziomoD = ileLiter(poziomoD);			
	}
	
	int dlugoscPionowoP = 0;
	int licznik = 0;
	do {
		losoweSlowo(file, bibliotekaPoczatki, poziomoG[dlugoscPoziomoG-1], pionowoP);
		dlugoscPionowoP = ileLiter(pionowoP);
		
		licznik++;
		//printf("%d ", licznik);
		
		if (licznik > 50) {
			flaga = 0;
			break;
		}
							
	} while (dlugoscPionowoP != dlugoscPionowoL || poziomoD[dlugoscPoziomoD-1] != pionowoP[dlugoscPionowoP-1]);
	
	}
	
	//printf("%s", poziomoG);
	//printf("%s", pionowoL);
	//printf("%s", poziomoD);
	//printf("%s\n\n", pionowoP);
	
	drukujHaslo (poziomoG, poziomoD, pionowoL, pionowoP, dlugoscPoziomoG, dlugoscPionowoL);
		
	fclose(file);	
	return 0;
}
