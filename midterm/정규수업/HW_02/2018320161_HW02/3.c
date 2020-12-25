#include <stdio.h>

int main(void)
{
	int value, fix, fec;
	value = -1;
	fec = 1;

	while (value < 0) {
		printf("Enter a positive integer: ");
		scanf_s("%d", &value);
		fix = value;
	}

	while (value > 0) {
		fec *= value;
		value--;
	}

	printf("%d! is %d\n", fix, fec);

	return 0;
}