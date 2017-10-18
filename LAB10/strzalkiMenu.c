#include <stdio.h>
#include <conio.h>
#include <windows.h>

void arrow(void) {
	
	printf("\n\t> Nowy zapis\n");
	printf("\t  Odczyt ostatniego zapisu\n\n");
	printf("\tNacisnij spacje aby zatwierdzic.");
	
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
			printf("\tNacisnij spacje aby zatwierdzic.");
		}
		if (key == 2) {
			printf("\n\t  Nowy zapis\n");
			printf("\t> Odczyt ostatniego zapisu\n\n");
			printf("\tNacisnij spacje aby zatwierdzic.");
		}
	} while (ch != 32);
}

int main(void) {
	
	arrow();
	getch();
}


