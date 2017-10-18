#include <stdio.h>

int main (void) {
	
	char ciag1[256], ciag2[256];
	
	printf("Podaj pierwszy ciag znakow: ");
	fgets(ciag1, 256, stdin);
	printf("Podaj drugi ciag znakow: ");
	fgets(ciag2, 256, stdin);
	
	int index = 0, ilosc = 0;
	
	while(ciag1[index] != 0) {

		int index_wew = 0;
		while(ciag2[index_wew] != 0) {

			if (ciag1[index] == ciag2[index_wew] && ciag1[index] != '\n') {
				ilosc++;
				break;
			}
			index_wew++;
		}
		index++;
	}
	
	printf("Ilosc znakow z ciagu pierwszego, ktora znajduje swoj odpowiednik w ciagu dwa jest rowan %d", ilosc);
	return 0;
}
