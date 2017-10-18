#include <stdio.h>
#include <time.h>


int miesiac(int m){
    /* Funkcja oczekuje wprowadzenia liczby od 1-12, która stanowi numer miesiaca w roku.
    W odpowiedzi zwraca iloœæ dni w danym miesi¹cu*/

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    }
    else if (m == 2){
        return 29;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        return 30;
    }
    else{
        printf("\n\tNIEPOPRAWNY WYBOR. SPROBOJ PONOWNIE.");
    }
}

void druk(int mies, int dzien){
    /* Funkcja przyjmuje dwie wartoœci typu int:
    1 - Numer miesiaca 1-12
    2 - Numer dnia 0-6
    Funkcja drukuje na ekran kartkê z kalendarza  */

    int dlugosc = miesiac(mies);
    system("cls");
    printf("\n\t");
    nazwa(mies);
    printf("\n\n\t|Ni |Po |Wt |Sr |Cz |Pt |So |\n\t");
    printf("-----------------------------\n\t");

    int i;
    for(i = 0; i < dzien; i++){
        printf("|   ");
    }

    int k;
    for(k = 1; k <= dlugosc; k++){
        if ((dzien - 1 + k)%7 ==0){
            printf("|\n\t");
        }
        printf("|%2d ", k);
    }

    if ((dlugosc + dzien)%7 != 0){
        int j;
        for(j = 0; j < (7 -((dlugosc + dzien)%7)); j++){
            printf("|   ");
        }
    }
    printf("|\n\n\t");
    (void)getch();
}

int nazwa(int i){
    /*Funkcja przyjmuje numer miesiaca 1-12.
    W zamian drukuje nazwe miesiaca o odpowiednim mumerze*/

    switch(i){
        case 1:
              printf("STYCZEN");
              break;
        case 2:
              printf("LUTY");
              break;
        case 3:
              printf("MARZEC");
              break;
        case 4:
              printf("KWIECIEN");
              break;
        case 5:
              printf("MAJ");
              break;
        case 6:
              printf("CZERWIEC");
              break;
        case 7:
              printf("LIPIEC");
              break;
        case 8:
              printf("SIERPIEN");
              break;
        case 9:
              printf("WRZESIEN");
              break;
        case 10:
              printf("PAZDZIERNIK");
              break;
        case 11:
              printf("LISTOPAD");
              break;
        case 12:
              printf("GRUDZIEN");
              break;
    }
}

int dane(int *miesiac, int *dzien){
    /*Pobieranie danych dotycz¹cych miesiaca oraz pierwszego dnia mieiaca od u¿ytkownika.*/

    int tempx, tempy;
    printf("\n\tPodaj numer miesiaca: ");
    while(1){
        scanf("%d", &tempx);
        if (tempx>0 && tempx<13){
            *miesiac = tempx;
            break;
        }
        else{
            system("cls");
            printf("\n\tNIEPRAWIDLOWE DANE. SPROBOJ PONOWNIE.\n\t");
        }

    }

    system("cls");
    printf("\n\tPodaj numer dnia: ");
    while(1){
        scanf("%d", &tempy);
        if (tempy>=0 && tempy<=6){
            *dzien = tempy;
            break;
        }
        else{
            system("cls");
            printf("\n\tNIEPRAWIDLOWE DANE. SPROBOJ PONOWNIE.\n\t");
        }

    }
}

int ddata(int *dzien,int *miesiac, int *dzienTyg){
    /*Funkcja pobiera z systemu operacyjnego nastepujace informacjie:
    1. Dzien miesiaca
    2. Obecny miesiac
    3. Dzien tygodnia.*/

    time_t time_raw_format;
    struct tm * ptr_time;
    char buffer[4];

    time ( &time_raw_format );
    ptr_time = localtime ( &time_raw_format );

    strftime(buffer,4,"%d",ptr_time);
    *dzien = atoi(buffer);
    strftime(buffer,4,"%m",ptr_time);
    *miesiac = atoi(buffer);
    strftime(buffer,4,"%w",ptr_time);
    *dzienTyg = atoi(buffer);
}

void kalendarzDzis(void){
    int dzien, miesiac, dzienTyg, startDay;
    ddata(&dzien, &miesiac, &dzienTyg);
    startDay = (7 + dzienTyg - (dzien%7 - 1))%7;
    printf("%d", startDay);

    druk(miesiac, startDay);
}

int main(void){
/*    int x, y;
    dane(&x,&y);
    druk(x,y); */
    kalendarzDzis();

    return 0;
}
