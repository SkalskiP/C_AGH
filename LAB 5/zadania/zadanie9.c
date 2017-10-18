#include <stdio.h>

int main (void) {
	int x = 4, y = 3;
	int wynik[y][x];
	
	const int matrix_2[3][4]=
{
    {1, 5, 6, 7},
    {4, 4, 8, 0},
    {2, 3, 4, 5}
};

	const int matrix_1[3][3]=
{
    {1, 5, 7},
    {4, 4, 0},
    {2, 3, 5}
};	
	
	int index_x, index_y;
	
	for (index_y = 0; index_y < y; index_y++) {
		
		for (index_x = 0; index_x < x; index_x++) {
			
			wynik[index_y][index_x] = 0;
			
			int index_sum;
			for(index_sum = 0; index_sum < 3; index_sum++) {
				wynik[index_y][index_x] += matrix_2[index_sum][index_x]*matrix_1[index_y][index_sum];
			}
			
			printf("%4d", wynik[index_y][index_x]);
			
		}
		printf("\n");
	}
	
	
	return 0;
}
