#include <stdio.h>

int main (void) {
	
	/* Kompilator rezerwuje obszar pamieci r�wny lub wiekszy, od sumy wielkosci wszystkich skladnikow Struktury
	Ka�dy element Struktury jest ulokowany w oddzielnym miejscu zarezerwowanej pamieci
	Mo�emy przechowywa� informacj� we wszystkich polach na raz
	Adres wszystkich zmiennych jest nadawany w kolejno�ci deklaracjii
	Struktury przechowuj� dane niezale�ne od siebie
	Mog� zainicjowa� wszystkie sk�adowe Struktury
	*/
	struct Person {
		int age;
		char name[6]; //6 bajtow
		float height;
		} ;
		
	/* Kompilator rezerwuje obszar pamieci r�wny najwiekszemu skladnikowi Unii
	Pami�� jest dzielona pomiedzy wszystkich u�ytkownik�w Unii
	Mo�emy przechowywa� informacj� tylko w jednym polu Unii
	Warto�� jednego elementu Unii w pewnym sensie oddaje warto�� pozosta�ych
	Mog� zainicjowa� tylko jedn� sk�adow� struktury, po zainictowaniu innej sk�adowej, warto�� wcze�niej zainicjowanej sk�adowej zostaje utracona.
	*/	
	union Student {
		int age;
		char name[6];
		float height;
	} ;
	
	printf("%d\n", sizeof(struct Person));
	printf("%d", sizeof(union Student));
	
	getch();
	return 0;
}
