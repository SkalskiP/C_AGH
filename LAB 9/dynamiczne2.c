#include <stdio.h>
#include <stdlib.h>

int main (void) {
	
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
    
    printf("%s", tekst);
    
	return 0;		
}
