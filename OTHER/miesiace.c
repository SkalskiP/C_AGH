#include <stdio.h>
#include <time.h>

int main ()
{
int d    = 1   ; //Day     1-31

int m    = 10    ; //Month   1-12

int y    = 2016 ; //Year    2013

int weekday ; // WeekDay ( Sunday - 0,Monday- 1,.....)

weekday  = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7  ;
printf("%d", weekday);

}
