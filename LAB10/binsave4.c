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

void dodajBackZPliku(Lista *list, Element* element) {
	
	
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

void stworzListe(Lista *list) {
	
	init(list);
	
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
}

void binarnyZapisListy(Lista *list) {
	
	FILE *ptr_myfile;
	Element* n = list -> head;
	
	int counter;
	
	ptr_myfile=fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB10\\test.bin","wb");
	if (!ptr_myfile) {
		printf("Unable to open file!");
		
	}
	else {
	
		for ( counter=1; counter <= list -> size; counter++) {
			
			fwrite(n, sizeof(Element), 1, ptr_myfile);
			
			if (counter != list -> size) {
				n = n->next;
			}
			
		}
	}
fclose(ptr_myfile);
}

void binarnyOdczytListy(Lista *Nowa) {
	
	FILE *ptr_myfile;
	
	int counter;
	
	ptr_myfile=fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB10\\test.bin","rb");
	if (!ptr_myfile) {
		printf("Unable to open file!");
	}
	else {
		
		fseek(ptr_myfile, 0L, SEEK_END);
		int iloscStruktur = ftell(ptr_myfile)/sizeof(Element);
		
		fseek(ptr_myfile, 0L, SEEK_SET);
		
		for ( counter=1; counter <= iloscStruktur; counter++) {
			
			Element* n = (Element*)malloc(sizeof(Element));
			fread(n, sizeof(Element),1,ptr_myfile);			
			dodajBackZPliku(Nowa, n);
		}
	}
	fclose(ptr_myfile);	
}

int menu(void) {
	
	printf("\n\t> Przegladaj ksiegozbior\n");
	printf("\t  Wyszukaj ksiazke po autorze\n");
	printf("\t  Dodaj element do ksiegozbioru\n");
	printf("\t  Wyjdz z ksiegozbioru\n\n");
	printf("\t  Nacisnij spacje aby zatwierdzic.");
	
	char ch;
	int key=1;
	
	do {
		ch=getch();
		system("cls");
	
		if (ch==72) {
			key--;
		}
		if (ch==80) {
			key++;
		}
		if (key==5) {
			key=1;
		}
		if (key==0) {
			key=4;
		}
		
		if (key == 1) {
			
			printf("\n\t> Przegladaj ksiegozbior\n");
			printf("\t  Wyszukaj ksiazke po autorze\n");
			printf("\t  Dodaj element do ksiegozbioru\n");
			printf("\t  Wyjdz z ksiegozbioru\n\n");
			
		}
		if (key == 2) {
			printf("\n\t  Przegladaj ksiegozbior\n");
			printf("\t> Wyszukaj ksiazke po autorze\n");
			printf("\t  Dodaj element do ksiegozbioru\n");
			printf("\t  Wyjdz z ksiegozbioru\n\n");
			
		}
		if (key == 3) {
			printf("\n\t  Przegladaj ksiegozbior\n");
			printf("\t  Wyszukaj ksiazke po autorze\n");
			printf("\t> Dodaj element do ksiegozbioru\n");
			printf("\t  Wyjdz z ksiegozbioru\n\n");
			
		}
		if (key == 4) {
			printf("\n\t  Przegladaj ksiegozbior\n");
			printf("\t  Wyszukaj ksiazke po autorze\n");
			printf("\t  Dodaj element do ksiegozbioru\n");
			printf("\t> Wyjdz z ksiegozbioru\n\n");
			
		}
		printf("\t  Nacisnij spacje aby zatwierdzic.\n");
	} while (ch != 32);
	
	system("cls");
	return key;
}


int main (void) {
	/*
	int flaga = 1;
	
	while (flaga) {
		
		int decyzja = menu();
		
		if (decyzja == 1) {
			
		}
		if (decyzja == 4) {
			flaga = 0;
		}
		
	}*/
	
	/*
	Lista Ksiazki;
	stworzListe(&Ksiazki);
	binarnyZapisListy(&Ksiazki);
	*/
	
	Lista Nowa;
	init (&Nowa);
	binarnyOdczytListy(&Nowa);
	printFront(&Nowa);
	
	return 0;
}
