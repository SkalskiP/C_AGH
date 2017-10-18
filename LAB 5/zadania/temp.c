#include <stdio.h>

int main (void) {
	
	char znak;
	scanf("%c", &znak);
	
	if (znak == 'x') printf("krzyzyk");
	else if (znak == 'o') printf("kolko");
	else if (znak == ' ') printf("spacja");
	else printf ("inne");
	
	return 0;
}
