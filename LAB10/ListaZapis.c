#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

typedef struct tagElement {
	/* Struktura dzialajaca jako pojedynczy element listy. Element przechowuje wymagane dane, oraz dwa wskazniki - do elementu wczesniejszego oraz do kolejnego.*/
	
	struct tagElement* next; /*Wskaznik do elementu kolejnego*/
	struct tagElement* prev; /*Wskaznik do elementu wczesniejszego*/
	
	/* Dane przenoszone wewnatrz pojedynczego elementu listy [zgodnie z trescia zadania] */
	char* autor;
	char* tytul;
	int numerKatalogowy;
	double cena;

}Element;

typedef struct tagList {
	/* Struktura pelniaca role listy. Sklada sie ze wskaznikow do struktur o nazwie Element oraz indexu pelniacego role licznika.*/
	
	Element* head; /* Pierwszy element listy */
	Element* tail; /* Ostatni element listy */
	
	int size; //Rozmiar listy [ilosc elementow]
	
}Lista;

void init(Lista* list) {
	/* Funkcja tworzaca liste o podanej nazwie. Parametry listy zostaja ustawione na 0.*/
	
	list->head=0;
	list->tail=0;
	list->size=0;
}

void zbudujElement(Element* ksiazka) {
	
	fseek(stdin,0,SEEK_END);
	
	printf("Podaj imie oraz nazwisko autora ksiazki: ");
	ksiazka->autor = pobierzString();
	
	printf("Podaj tutul kiazki: ");
	ksiazka->tytul = pobierzString();
	
	fseek(stdin,0,SEEK_END);
	
	printf("Podaj numer katalogowy [liczba]: ");
	scanf("%d", &(ksiazka->numerKatalogowy));
	
	printf("Podaj cene: ");
	scanf("%lf", &(ksiazka->cena));
	
}

void dodajFront(Lista *list) {
	
	Element* element = (Element*)malloc(sizeof(Element));
	zbudujElement(element);
	element->prev = 0;
	element->next = list->head;
	
	
	if (list->size == 0){
		list->head = element;
		list->tail = element;
		list->size++;
	}
	else {
		list->head->prev = element;
		list->head = element;
		list->size++;
	}
		
}

void dodajBack(Lista *list) {
	
	Element* element = (Element*)malloc(sizeof(Element));
	zbudujElement(element);
	element->prev = list->tail;
	element->next = 0;
	
	
	if (list->size == 0){
		list->head = element;
		list->tail = element;
		list->size++;
	}
	else {
		list->tail->next = element;
		list->tail = element;
		list->size++;	
	}
}

void printFront (Lista *list) {
	
	Element* bierzacy= list->head;
	
	int index;
	for (index = 0; index < list->size; index++) {
		printf("Tytul: %s", bierzacy->autor);
		printf("Autor: %s", bierzacy->tytul);
		printf("Numer Katalogowy: %d\n", bierzacy->numerKatalogowy);
		printf("Cena: %.2lf\n", bierzacy->cena);
		printf("---------------------\n");
		bierzacy=bierzacy->next;
	}
}

void printBack (Lista *list) {
	
	Element* bierzacy= list->tail;
	
	int index;
	for (index = 0; index < list->size; index++) {
		printf("Tytul: %s", bierzacy->autor);
		printf("Autor: %s", bierzacy->tytul);
		printf("Numer Katalogowy: %d\n", bierzacy->numerKatalogowy);
		printf("Cena: %.2lf\n", bierzacy->cena);
		printf("---------------------\n");
		bierzacy=bierzacy->prev;
	}
}

void filePrintFront (Lista *list, FILE *file) {
	
	Element* bierzacy = list->head;
	
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    fprintf(file, "Data zapisu: %s\n\n", asctime(tm));
	
	int index;
	for (index = 0; index < list->size; index++) {
		fprintf(file, "Tytul: %s", bierzacy->autor);
		fprintf(file, "Autor: %s", bierzacy->tytul);
		fprintf(file, "Numer Katalogowy: %d\n", bierzacy->numerKatalogowy);
		fprintf(file, "Cena: %.2lf\n", bierzacy->cena);
		fprintf(file, "---------------------\n");
		bierzacy=bierzacy->next;
	}
}

int menu(void) {
	
	printf("\n\t> Nowy zapis\n");
	printf("\t  Odczyt ostatniego zapisu\n\n");
	printf("\t  Nacisnij spacje aby zatwierdzic.");
	
	char ch;
	int key=1;
	
	do {
		ch=getch();
		system("cls");
	
		if (ch==72) {
			key++;
		}
		if (key==3) {
			key=1;
		}
		if (ch==80) {
			key--;
		}
		if (key==0) {
			key=2;
		}
		
		if (key == 1) {
			
			printf("\n\t> Nowy zapis\n");
			printf("\t  Odczyt ostatniego zapisu\n\n");
			printf("\t  Nacisnij spacje aby zatwierdzic.");
		}
		if (key == 2) {
			printf("\n\t  Nowy zapis\n");
			printf("\t> Odczyt ostatniego zapisu\n\n");
			printf("\t  Nacisnij spacje aby zatwierdzic.");
		}
	} while (ch != 32);
	
	system("cls");
	return key;
}

void zapiszListe(Lista *list) {
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB10\\zapis.txt", "w+");
	srand(time(NULL));	
	
	if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
    }
    else {
    	filePrintFront (list, file);
	}
	close(file);
}

void stworzListe(Lista *list) {
	
	char ch;
	init(list);
	
	do {	
		ch = 0;
	
		do {
			system("cls");
			printf("Czy chcesz wprowadzic nowy element ksiegozbioru? [t/n]");
			ch = getch();
		} while ((ch != 't') && (ch != 'n'));
		
		if (ch == 't') {
			system("cls");
			dodajFront(list);
		}
		
	} while (ch != 'n');
	
	zapiszListe(list);	
}

void odczytajPlik(void) {
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB10\\zapis.txt", "r");
	srand(time(NULL));	
	
	if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
    }
    else {
    	
    	char buffor[50];
    	while (!feof(file)) {
        	fgets(buffor, 50, file);
        	printf("%s", buffor);
        }
	
	}
	close(file);
	
}

void sekPrzegladListy(Lista *list) {
	
	int wielkosc = list->size;
	
	char ch;
	int key = 1;
	
	do {
		ch=getch();
		system("cls");
	
		if (ch==72) {
			key++;
		}
		if (key==3) {
			key=1;
		}
		if (ch==80) {
			key--;
		}
		if (key==0) {
			key=2;
		}
		
		if (key == 1) {
			
			printf("\n\t> Nowy zapis\n");
			printf("\t  Odczyt ostatniego zapisu\n\n");
			printf("\t  Nacisnij spacje aby zatwierdzic.");
		}
		if (key == 2) {
			printf("\n\t  Nowy zapis\n");
			printf("\t> Odczyt ostatniego zapisu\n\n");
			printf("\t  Nacisnij spacje aby zatwierdzic.");
		}
	} while (ch != 32);
	
	
}

void odczytajWybrany(Lista *list, int wybrany) {
	
	int wielkosc = list->size;
	Element* biezacy= list->head;
	
	int index;
	
	
	for(index = 1; index <= wybrany; index++) {
		biezacy = biezacy->next;
	}
	
	printf("Tytul: %s", biezacy->autor);
	printf("Autor: %s", biezacy->tytul);
	printf("Numer Katalogowy: %d\n", biezacy->numerKatalogowy);
	printf("Cena: %.2lf\n", biezacy->cena);
	
}


int main(void) {
	
	int wybor;
	wybor = menu();
	
	if(wybor == 1) {
		Lista Ksiazki;
		stworzListe(&Ksiazki);
		//printFront (&Ksiazki);
		
		odczytajWybrany(&Ksiazki, 2);
	} 
	else odczytajPlik();
	
	
	/*init(&Ksiazki); 
	dodajFront(&Ksiazki);
	dodajFront(&Ksiazki);
	dodajFront(&Ksiazki);
	dodajBack(&Ksiazki);
	printFront (&Ksiazki);*/
	
	
	return 0;
}

