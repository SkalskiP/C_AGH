#include <stdio.h>

int silniaIter (int podstawa);
int silniaRec (int podstawa);

int main (void) {
	
	int liczba, silniaI, silniaR;
	printf("Podaj podstawe silni: ");
	scanf("%d", &liczba);
	
	silniaI = silniaIter(liczba);
	silniaR = silniaRec(liczba);
	printf("Wartosc obliczona poprzez iteracje: %d\n", silniaI);
	printf("Wartosc obliczona poprzez rekurencje: %d\n", silniaR);
	
	return 0;
	
}

int silniaIter (int podstawa) {
	
	int silnia = 1;
	
	if (podstawa == 0) return silnia;
	
	else if (podstawa >= 1) {
		
		int index;
		for (index = 1; index <= podstawa; index ++) {
			silnia = silnia*index;
		}
		return silnia;
	} 
}

int silniaRec (int podstawa) {
	
	if (podstawa == 0 || podstawa == 1) {
		return 1;
	}
	
	else if(podstawa > 1) {
		return podstawa*silniaRec(podstawa - 1);
	}
	
}
