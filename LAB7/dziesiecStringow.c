#include <stdio.h>

int main (void) {
	
	int iloscStringow;
	
	FILE *file;
	file = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\nowyslownik.txt", "r");
	
	
	printf("Podaj ilosc ciag zankow: ");
	scanf("%d", &iloscStringow);
	//printf("%d", iloscStringow);
	
	char stringi[iloscStringow][50];
	
	int licznik = 1;
	
	while (!feof(file) && (licznik <= iloscStringow)) {
        fgets(stringi[licznik-1], 49, file);
    
        if (licznik == wiersz) break;
        licznik++;
	}
	
	return 0;
}
