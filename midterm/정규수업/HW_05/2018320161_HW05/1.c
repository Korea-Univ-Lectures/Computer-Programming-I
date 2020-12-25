#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int arr[20];
	int i, j;

	printf("Nonrepititive array values are:\n");
	srand((unsigned)time(NULL));

	for (i = 0; i < 20; i++) {
		arr[i] = (rand() % 20) + 1;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] == arr[i]) {
				arr[i] = (rand() % 20) + 1;
				i--;
			}
		}
	}

	for (i = 0; i < 20; i++) {
		printf("Array[%d]:%d\n", i, arr[i]);
	}
	return 0;
}
