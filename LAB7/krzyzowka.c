#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    FILE *f;
    int nLines = 0;
    char line[1024], wiersz[1024];
    int randLine;
    int i;

    srand(time(0));
    f = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\slowa.txt", "r");

/* 1st pass - count the lines. */
    while(!feof(f))
    {
        fgets(line, 1024, f);
        nLines++;
    }
    
    printf("%d", nLines);
    
}

