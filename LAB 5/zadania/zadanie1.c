#include <stdio.h>

int main (void) {
	
	char buffer[256];
	char often = (char) 0;
	int index = 0, ilosc = 0;
	
	printf("Podaj ciag znakow: ");
	fgets(buffer, 256, stdin);
	
	
	while(buffer[index] != 0) {
		
		int licznik = 0;
		int index_wew = index;
		
		while(buffer[index_wew] != 0) {
			if (buffer[index] == buffer[index_wew]) {
				licznik++;
			}
			index_wew++;
		}
		
		if (licznik>ilosc) {
			often = buffer[index];
			ilosc = licznik;
		}	
		index++;
	}
	
	printf("Najczesciej powtarzajacy sie znak to: %c.\n", often);
	printf("Ilosc powtorzen wynosi: %d.\n", ilosc);
	
	return 0;
}
