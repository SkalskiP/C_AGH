#include <stdio.h>
#include <stdlib.h>

typedef struct tagElement {
	
	struct tagElement* next;
	
	char autor[50];
	char tytul[50];
	int numer;
	double cena;
	
} Element;

typedef  struct tagLista {
	
	Element* head;
	int size;
	
}Lista;

void init(Lista* lista) {
	lista -> head = 0;
	lista -> size = 0;
}

void pobierzElement(Element* nowyElement) {
	
	fseek(stdin,0,SEEK_END);
	
	printf("\nPodaj autora utworu: ");
	fgets(nowyElement->autor, 50, stdin);
	printf("\nPodaj tytul utworu: ");
	fgets(nowyElement->tytul, 50, stdin);
	printf("\nPodaj numer katalogowy utworu: ");
	scanf("%d", &(nowyElement-> numer));
	printf("\nPodaj cene utworu: ");
	scanf("%lf", &(nowyElement-> cena));
	
	
}

void addElement(Lista* lista) {
	
	Element* nowyElement = (Element *)malloc(sizeof(Element));
	pobierzElement(nowyElement);
	nowyElement -> next = lista -> head;
	lista -> head = nowyElement;
	lista -> size++;
	
}

void printElement(Element* element) {
	printf("%s", element -> autor);
	printf("%s", element -> tytul);
	printf("%d\n", element -> numer);
	printf("%.2lf\n", element -> cena);
	printf("----------------------\n");
}

void printList(Lista* lista) {
	
	int index;
	Element* n = lista -> head;
	for(index = 0; index < lista -> size; index++) {
		printElement(n);
		n = n -> next;
	}
	
}

Lista reverseList(Lista* staraLista) {
	Lista nowaLista;
	init(&nowaLista);
	Element* tablicaWskaznikow[staraLista -> size];
	Element* n = staraLista -> head;
	
	int index;
	for(index = 0; index < staraLista -> size; index++) {
		tablicaWskaznikow[index] = n;
		printf("%d\n", n);
		n = n -> next;
	}
	
	
	
	nowaLista.head = tablicaWskaznikow[staraLista -> size -1];
	nowaLista.head -> next = 0;
	nowaLista.size++;
	
	//printf("%d\n", nowaLista.head);
	//printf("%d\n", nowaLista.head);
	
	for(index = staraLista -> size -2; index >= 0; index--) {
		tablicaWskaznikow[index] -> next = nowaLista.head;
		nowaLista.head = tablicaWskaznikow[index];
		//printf("%d\n", nowaLista.head);
		nowaLista.size++;
	}
	
	return nowaLista;
}

int main(void) {

	Lista nowaLista;
	init(&nowaLista);
	addElement(&nowaLista);
	addElement(&nowaLista);
	addElement(&nowaLista);
	
	printList(&nowaLista);
	Lista obroconaLista = reverseList(&nowaLista);
	printList(&obroconaLista);
	
	return 0;
}
