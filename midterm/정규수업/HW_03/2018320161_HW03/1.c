#include <stdio.h>

int main(void) {

	int value, max=0, i = 0;

	do {
		printf("Enter the number: ");
		scanf_s("%d",&value);
		i++;
		if (i == 0)max = value;
		if (max < value) max = value;
	} while (i<5);

	printf("Largest is %d \n", max);

	return 0;
}