#include <stdio.h>

int perfect(int x);

int main(void) {
	int a = 100000, j, judge;
	printf("For the integers from 1 to %d\n----------------------------------\n", a);

	for (j = 1; j <= a; j++) {
		if (perfect(j)) printf("%d is Perfect\n", j);
	}

	return 0;
}

int perfect(int x) {
	int i, sum = 0;

	for (i = 1; i < x; i++) if (x%i == 0) sum += i;
	x = x == sum ? 1 : 0;

	return x;
}
