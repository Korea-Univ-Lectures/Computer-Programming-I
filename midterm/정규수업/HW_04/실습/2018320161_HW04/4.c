#include <stdio.h>

int inverse2(int x);

int main(void) {

	int value = 0;

	while (value <= 0) {
	printf("Enter a number between 1 to 9999:");
	scanf("%d", &value);
	}
	value = inverse2(value);
	printf("The number with its digits reversed is:%d\n",value);
}

int inverse2(int value) {

	int inverse = 0;

	while (value>0) {
		inverse *= 10;
		inverse += value % 10;
		value = value / 10;
	}

	return inverse;
}