#include <stdio.h>

int main()
{
    FILE *f = fopen("C:\\Users\\AFGHAN\\Desktop\\C\\LAB7\\szybkiTest.txt", "r+");
    if (f == NULL)
        return 1;

    fseek(f, -5, 2);   // dziesi�ta pozycja od ko�ca

    long offset = ftell(f);
    printf("Pozycja w pliku: %d\n", offset);

    fclose(f);
    return 0;
}
