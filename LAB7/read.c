#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drukowanieTablicy(char tablica[], int wielkosc) {
	
	int index;
	
	for (index = 0; index < wielkosc; index++) {
		printf("%c", tablica[index]);
	}
}

int main(int argc, char *argv[]) {

	char c;
	/*zmienna przechowuj�ca bie��cy znak*/ 
	
	int litera = 1, LICZNIK = 0, MAX = 0;
	/*litera - zmienna pomocnicza wskazuj�ca, ze natrafiono na liter� [0 gdy znak jest liter�, 1 gdy inny znak]
	LICZNIK - wskazuje d�ugo�� bie��cego s�owa
	MAX - wskazuje d�ugo�� najd�u�szego s�owa*/
	
	char buffor[40], tmp[40];
	/*buffor - tabica przechowuj�ca najd�u�sze, znalezione do tej pory s�owo
	tmp - tablica przechowuj�ca tre�� bierz�cego s�owa*/
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\Polecenia.txt", "r");
	
	if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
	
	else if (file) {
    	do {
        	
        	if ((c >=48 && c <= 57) || (c >=65 && c <= 90) || (c >=97 && c <= 122)) {
        		tmp[LICZNIK] = c;
        		LICZNIK++;
        		litera = 0;
			}
			else {
				if (litera == 0) {
					if (LICZNIK != 0 && LICZNIK > MAX) {
						MAX = LICZNIK;
						strcpy(buffor, tmp);
					}
					LICZNIK = 0;
				}
				litera = 1;
			}
		} while ((c = getc(file)) != EOF);
		
    	fclose(file);
	}
	printf("%d ", MAX);
	drukowanieTablicy(buffor, MAX);
}
