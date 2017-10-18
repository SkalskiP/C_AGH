#include <stdio.h>

int main (void) {
	
	/* Kompilator rezerwuje obszar pamieci równy lub wiekszy, od sumy wielkosci wszystkich skladnikow Struktury
	Ka¿dy element Struktury jest ulokowany w oddzielnym miejscu zarezerwowanej pamieci
	Mo¿emy przechowywaæ informacjê we wszystkich polach na raz
	Adres wszystkich zmiennych jest nadawany w kolejnoœci deklaracjii
	Struktury przechowuj¹ dane niezale¿ne od siebie
	Mogê zainicjowaæ wszystkie sk³adowe Struktury
	*/
	struct Person {
		int age;
		char name[6]; //6 bajtow
		float height;
		} ;
		
	/* Kompilator rezerwuje obszar pamieci równy najwiekszemu skladnikowi Unii
	Pamiêæ jest dzielona pomiedzy wszystkich u¿ytkowników Unii
	Mo¿emy przechowywaæ informacjê tylko w jednym polu Unii
	Wartoœæ jednego elementu Unii w pewnym sensie oddaje wartoœæ pozosta³ych
	Mogê zainicjowaæ tylko jedn¹ sk³adow¹ struktury, po zainictowaniu innej sk³adowej, wartoœæ wczeœniej zainicjowanej sk³adowej zostaje utracona.
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
