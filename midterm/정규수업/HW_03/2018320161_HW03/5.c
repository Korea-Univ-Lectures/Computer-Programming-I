#include <stdio.h>

int main(void) {
	double pi = 0;
	double num = 4;
	double denom = 1;
	long int loop;
	long int accuracy = 900000;

	printf("Accuarcy set at %d\n",accuracy);
	printf("term\t\t  pi \n");

	for (loop = 1; loop <= accuracy; loop++) {
		denom = 2*loop-1;
		if (loop % 2 == 1)pi += num / denom;
		else pi -= num / denom;
		if (loop % 50000 == 0)printf("%d\t\t%.6f\n",loop,pi);
	}
	return 0;
}