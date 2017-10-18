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
	/*zmienna przechowuj¹ca bie¿¹cy znak*/ 
	
	int litera = 1, LICZNIK = 0, MAX = 0;
	/*litera - zmienna pomocnicza wskazuj¹ca, ze natrafiono na literê [0 gdy znak jest liter¹, 1 gdy inny znak]
	LICZNIK - wskazuje d³ugoœæ bie¿¹cego s³owa
	MAX - wskazuje d³ugoœæ najd³u¿szego s³owa*/
	
	char buffor[40], tmp[40];
	/*buffor - tabica przechowuj¹ca najd³u¿sze, znalezione do tej pory s³owo
	tmp - tablica przechowuj¹ca treœæ bierz¹cego s³owa*/
	
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
