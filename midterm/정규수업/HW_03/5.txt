#include <stdio.h>

int main(void) {

	int i, j, min, max= 1;

	for (j = 1; j < 6;j++) {

		for (i = 9; i > 0; i--) {
			min = 6 - j;
			max = j + 4;
			if (i >= min && i <= max)printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	for (j = 4; j >0; j--) {

		for (i = 9; i > 0; i--) {
			min = 6 - j;
			max = j + 4;
			if (i >= min && i <= max)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}