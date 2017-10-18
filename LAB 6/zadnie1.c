#include <stdio.h>

void min_max (int tab[], int n, int*min, int*max) {
	int i;
	*max = *min = tab[0];
	for (i=0; i<n; i++) {
		if (*min>tab[i])*min = tab[i];
		if (*max<tab[i])*max = tab[i];
	}
} 

int main (void) {
	
	int min_var, max_var;
	int t[] = {3, 4, 7, 2, -2, 234};
	min_max(t, sizeof t/sizeof t[0], &min_var, &max_var);
	printf("min = %d max = %d\n", min_var, max_var);
	
	return 0;
}
