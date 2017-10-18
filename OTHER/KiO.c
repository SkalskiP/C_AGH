#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {PUSTO, KOLKO, KRZYZYK};

void _nazwaGracza(const gracz) {
	switch(gracz)
	{
		case KOLKO:
			printf("KOLKO ");
			break;
		case KRZYZYK:
			printf("KRZYZYK ");
			break;
	}
}

void _stworzPoleGry(int *Tablica3x3) {
	/* Funkcja pobiera zadeklarowaną wcześniej tablicę o wymiarach 3x3 i wypełnia ją zerami */
	int index;
	for(index = 0; index < 9; index++) {
		Tablica3x3[index] = PUSTO;
	}
}

void _wyswietlPoleGry(const int *Tablica3x3) {
	int index;
	system("cls");
	char oznaczenia[] = "-OX";
	printf("-------------------------------\n");
	printf("\tKOLKO i KRZYZYK\n");
	printf("-------------------------------\n\n\t");
	for (index = 0; index <9; index++) {
		if (index !=0 && index%3 == 0) {
			printf("\n\n\t");
		}
		printf("%4c", oznaczenia[Tablica3x3[index]]);
	}
	printf("\n\n-------------------------------\n\n");
}

void _zrobRuch(int *Tablica3x3, const int pole, const gracz) {
	Tablica3x3[pole] = gracz;
}

int _koniecGryPion(int *Tablica3x3, const gracz) {
	int i, j;
	for(i = 0; i<3; i++) {
		int koniecGry =0;
		for(j = 0; j <3 ; j++) {
			if(Tablica3x3[j*3+i] == gracz) {
				koniecGry++;
			}
		}
		if (koniecGry == 3) return 0;
	}
	return 1;
}

int _koniecGryPoziom(int *Tablica3x3, const gracz) {
	int i, j;
	for(j = 0; j < 3; j++) {
		int koniecGry = 0;
		for(i = 0; i < 3 ; i++) {
			if(Tablica3x3[j*3+i] == gracz) {
				koniecGry++;
			}
		}
		if (koniecGry == 3) return 0;
	}
	return 1;
}

int _koniecGryRemis(int *Tablica3x3) {
	int i;
	int koniecGry = 0;
	for(i = 0; i < 9; i++) {
		if(Tablica3x3[i] == PUSTO) koniecGry++;
	}
	if(koniecGry == 0) return 0;
	return 1;
}

int _koniecGryUkos(int *Tablica3x3, const gracz) {
	int i;
	int koniecGry = 0;
	for(i = 0; i < 9; i=i+4) {
		if(Tablica3x3[i] == gracz) koniecGry++;
	}
	if(koniecGry == 3) return 0;

	koniecGry = 0;

	for(i = 2; i < 9; i=i+2) {
		if(Tablica3x3[i] == gracz) koniecGry++;
	}
	if(koniecGry == 3) return 0;
	return 1;
}

int _koniecGry(int *Tablica3x3, const gracz) {


	if (_koniecGryPion(Tablica3x3, gracz) == 0 || _koniecGryPoziom(Tablica3x3, gracz) == 0 || _koniecGryUkos(Tablica3x3, gracz) == 0) {
		printf("KONIEC GRY!\n");
		_nazwaGracza(gracz);
		printf("WYGRALES!\n");
		return 0;
	}
	if (_koniecGryRemis(Tablica3x3) == 0) {
		printf("KONIEC GRY!\nREMIS\n\n");
		return 0;
	}
	return 1;
}

void _startGry(int gracze) {
	int poleGry[9];
	int aktywnyGracz = KOLKO;
	int koniecGry = 1;

	_stworzPoleGry(&poleGry[0]);
	_wyswietlPoleGry(&poleGry[0]);

	if(gracze == 2) {
		while(koniecGry) {

			_zrobRuch(&poleGry[0], _pobierzRuchGracza(&poleGry[0], aktywnyGracz), aktywnyGracz);
			_wyswietlPoleGry(&poleGry[0]);
			koniecGry = _koniecGry(&poleGry[0], aktywnyGracz);

			if(aktywnyGracz == KOLKO) {
				aktywnyGracz = KRZYZYK;
			}
			else aktywnyGracz = KOLKO;
		}
	}

	if(gracze == 1) {
		while(koniecGry) {
			if(aktywnyGracz == KOLKO) {
				_zrobRuch(&poleGry[0], _pobierzRuchGracza(&poleGry[0], aktywnyGracz), aktywnyGracz);
				_wyswietlPoleGry(&poleGry[0]);
				koniecGry = _koniecGry(&poleGry[0], aktywnyGracz);
				aktywnyGracz = KRZYZYK;
			}
			else {
				_zrobRuch(&poleGry[0], _pobierzRuchKomputera(&poleGry[0]), aktywnyGracz);
				_wyswietlPoleGry(&poleGry[0]);
				koniecGry = _koniecGry(&poleGry[0], aktywnyGracz);
				aktywnyGracz = KOLKO;
			}
		}
	}


}

int _pobierzRuchKomputera(const int *Tablica3x3) {
	int ruch;
	while(1) {
	ruch = rand() % 9;
	if(Tablica3x3[ruch] == PUSTO) return ruch;
	}
}

int _pobierzRuchGracza(const int *Tablica3x3, const gracz) {
	while(1){

		int X, Y, ruch = 0;
		_nazwaGracza(gracz);
		printf("TWOJ RUCH!\n\n");
		printf("Podaj kolumne: ");
		X = _pobierzRuch();
		printf("\n\nPodaj wierwsz: ");
		Y = _pobierzRuch();

		ruch = 3*Y+X;

		if(Tablica3x3[ruch] != PUSTO) {
			printf("Wybrane pole jest zajete\n\n");
			continue;
		}
		printf("%d", ruch);
		return ruch;
	}
}

int _pobierzRuch() {

	/* Funkcja pobiera dane od gracza i weryfikuje ich poprawność. */

	char ruchGracza[4]; // Buffer
	int ruch; // Zmienna zapisujaca wartosc ruchu w postaci liczbowej

	while(1) {

		fgets(ruchGracza, 3, stdin); // Pobiera ciąg znaków o dlugości 3 ze standardowego wejscia i zapisuje do zmiennej ruchGracza.
		fflush(stdin); // Czyszczenie standardowego wejscia

		if(sscanf(ruchGracza, "%d", &ruch) != 1) { //Sprawdzenie czy wartość zapisana w zmiennej ruchGracza jest liczbą w systemie dziesietnym
			ruch = -1;
			printf("Wprowadzony ciag znakow jest niepoprawny\n");
			continue;
		}

		if (ruch < -1 || ruch > 3) {
			ruch = -1;
			printf("Wprowadzona wartosc nie miesci sie w zakresie od 1 do 3.\n");
			continue;
		}

		ruch--;
		break;
	}
	return ruch;
}

void _menu(void) {
	int wybor;


    system("cls");
	printf("-------------------------------\n");
	printf("\tKOLKO i KRZYZYK\n");
	printf("-------------------------------\n\n");
	printf("1. GRACZ vs GRACZ\n");
	printf("2. GRACZ vs KOMPUTER\n");
	printf("3. WYJSCIE\n\n");
	printf("-------------------------------\n");
	printf("TWOJ WYBOR: ");

	wybor = _pobierzRuch() +1;

	switch(wybor) {
		case 1:
			_startGry(2);
			break;
		case 2:
			_startGry(1);
			break;
		case 3:
			break;
	}

}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	char decyzja;

	_menu();

	return 0;

}
