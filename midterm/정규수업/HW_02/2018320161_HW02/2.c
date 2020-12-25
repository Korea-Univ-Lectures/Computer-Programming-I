#include <stdio.h>

int main(void)
{
	int a, b, c, d, sum;

	printf("Enter two integers: ");

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	c = a;
	d = b;

	if (a <= b) {

		sum = a;

		while (a < b) {

			a = a++;
			sum = sum + a;

		}

	}

	else {

		sum = b;

		while (b < a) {

			b = b++;
			sum = sum + b;

		}
	}

	printf("The sum of all intergers between %d and %d is %d \n", c, d, sum);

	return 0;

}