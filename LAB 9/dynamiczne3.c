#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pobierzString (void) {
	
	char *tekst = NULL, *tmp = NULL;
    int wielkosc = 0, index = 0, delta;
    char znak;
    delta = sizeof(char);
	
	int flaga = 1;
    do {
        znak = getc(stdin);

        /* sprawdzam czy wczytany znak to znak konca wiersza, jezeli tak to zmieniam flage na 0 -> to otatni obrot petli */
        if (znak == EOF || znak == '\n')
            flaga = 0;

        /* powiekszam pamiec o kolejny znak*/
        wielkosc += delta;
        tmp = realloc(tekst, wielkosc);
        if (!tmp) {
            free(tekst);
            tekst = NULL;
            break;
        }
        tekst = tmp;
        

        /* zapisuje znak w pamieci*/
        tekst[index] = znak;
        index ++;
    } while (flaga);
    
    return tekst;
	
}

int main (void) {
	 
	int ilosc;
	char** wsk;
	
	printf("Wprowadz ilosc wprowadzanych ciagow znakow: ");
	scanf("%d", &ilosc);
	
	wsk = (char**)malloc(ilosc*sizeof(char **));
	fseek(stdin,0,SEEK_END);
	
	int index;
	
	for(index = 0; index < ilosc; index++) {
		wsk[index] = pobierzString();
	}
	
	
	for(index = 0; index < ilosc; index++) {
		printf("%s", wsk[index]);
	}
	
	//char* tekst = pobierzString();
	//printf("%s", tekst);
	
	free(wsk);
	
	return 0;
}
