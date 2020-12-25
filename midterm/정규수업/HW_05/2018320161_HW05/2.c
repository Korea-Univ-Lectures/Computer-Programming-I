#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arraddprint(int arr1[][6], int arr2[][6]);

int main(void) {
	srand((unsigned)time(NULL));

	int arr1[5][6];
	int arr2[5][6];
	int i = 0, j = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			arr1[i][j] = rand() % 100 + 1;
			arr2[i][j] = rand() % 100 + 1;
		}
	}
	arraddprint(arr1, arr2);
}

int arraddprint(int arr1[][6], int arr2[][6]) {
	int arradd[5][6];
	int i = 0, j = 0;

	printf("matrix1:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			arradd[i][j] = arr1[i][j] + arr2[i][j];
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	printf("\nmatrix2:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	printf("\nresult:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			printf("%d ", arradd[i][j]);
		}
		printf("\n");
	}

	return 1;
}
