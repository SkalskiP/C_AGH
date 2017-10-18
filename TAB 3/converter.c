#include <stdio.h>
#include <ctype.h>

char reWeryfikacja (int liczba) {
	if (liczba <= 9 && liczba >= 0 ) {
		return(liczba + '0');
	}
	else {
		return((char)(liczba + 55));
	}
} 

int weryfikacja(char znak) {
	/* 
	ZADANIE: Funkcja werykikuje czy podany symbol jest cyfr¹ czy liter¹. Je¿eli symbol jest:
			1. liter¹ - zwraca odpowiednio przyporz¹dkowan¹ wartoœæ: dla A - 10, B -11 etc.
			2. cyfr¹ - zwraca wartoœæ tej cyfry
	*/
	if (isalpha(znak)) {
		return((int)znak - 55);
	} 
	else if (isdigit(znak)) {
    	return(znak - '0');
	}
}

int conv1 (char tablica[20], int podstawa) {
	/*
	ZADANIE: Funkcja konwertuje liczbê z systemu o podanej podstawie na liczbê w systemie dziesiêtnym.
	*/
	int suma = 0;
	int index = 0;
	
	do {
		suma = suma*podstawa;
		suma = suma + weryfikacja(tablica[index]);
		index ++;
	} while (tablica[index] != 0);
	
	return(suma);
}

int conv2 (int wDziesietnym, int podstawa2) {
	/*
	ZADANIE: Funkcja konwertuje liczbê z systemu dziesiêtnego na wybrany system liczbowy.
	*/
	char buf[20];
	int dlugosc = 0;
	while(wDziesietnym > 0) {
		
		buf[dlugosc] = reWeryfikacja (wDziesietnym%podstawa2);

		wDziesietnym = (int)(wDziesietnym/podstawa2);
		dlugosc++;
	}
	
	int index;
	for (index = dlugosc -1; index >= 0; index --) {
		printf("%c", buf[index]); 
	} 
}

int main(void) {
	
	int podstawa, podstawa2, suma;
	char buf[20];

	printf("WITAJ\n");

    printf("\nWprowadz podstawe wejsciowego systemu liczbowego: ");
    scanf("%d", &podstawa);
    
    printf("\nWprowadz podstawe wyjsciowego systemu liczbowego: ");
    scanf("%d", &podstawa2);

    printf("\nWprowadz liczbe w systemie o podstawie %d: ", podstawa);
    scanf("%s", buf);
    
    suma = conv1(buf, podstawa);
	
	printf("\n\nLiczba wprowadzona w systemie o podstawie %d, po przeliczeniu na system dziesietny jest rowna %d.\n", podstawa, suma);
	printf("\nA po przeliczeniu na system o podstawie %d jest rowna ", podstawa2);
	
	conv2 (suma, podstawa2);
	
    return 0;
}
