#include<stdio.h>
#include <string.h>

int main (void) {
	
	int iloscSlow, index;
	printf("Podaj liczbe analizowanych ciagow znakowych:\n");
	scanf("%d", &iloscSlow);
	
	char tablica[iloscSlow][101], temp[100]; 
	
	printf("Podaj kolejne ciagi znakowe. [maksymalna dlugosc ciagu to 100 znakow]:\n");
	
	for (index = 0; index < iloscSlow; index++) {
		 //fgets(tablica[index], 100, stdin);
		 scanf ("%s", tablica[index]);
	}
	
	for (index = iloscSlow-1; index >= 1; index--) {
		
		int index_wew;
		for(index_wew = 1; index_wew <= index; index_wew++) {
			
			if(strcmp(tablica[index_wew], tablica[index_wew-1]) < 0) {
				strcpy(temp, tablica[index_wew]);
				strcpy(tablica[index_wew], tablica[index_wew-1]);
				strcpy(tablica[index_wew-1], temp);
			}
			
		}
		
	}
	
	
	for (index = 0; index < iloscSlow; index++) {
		 printf("%s\n", tablica[index]);
	}
	
	return 0;
}
