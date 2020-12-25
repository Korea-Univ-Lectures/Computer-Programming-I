#include <stdio.h>

int main(void)
{
	int value, fix, count;
	count = 0;

	printf("Enter a integer: ");
	scanf_s("%d", &value);
	fix = value;

	if (value < 0) value = -value;

	while (value != 0) {
		if (value % 10 == 7) count++;
		value = value / 10;
	}

	printf("The number %d has %d seven(s) in it.\n", fix, count);

	return 0;
}