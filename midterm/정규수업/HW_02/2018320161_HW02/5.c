#include <stdio.h>

int main(void)
{
	int value, max, min, count;
	float add, avr;

	count = 0;
	printf("Enter the number: ");
	scanf_s("%d", &value);
	max = value;
	min = value;
	add = (float)value;

	while (value != 0) {
		printf("Enter the number: ");
		scanf_s("%d", &value);
		add = add + (float)value;
		count++;

		if (value > max) max = value;
		if (value < min) min = value;
	}

	if (count == 0)avr = 0;
	else avr = add / count;

	printf("User typed the numbers between %d and %d.\nThe average of the input numbers is %.2f \n", max, min, avr);

	return 0;
}