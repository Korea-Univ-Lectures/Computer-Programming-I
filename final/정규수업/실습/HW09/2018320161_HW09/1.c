#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputname(char* arr, int n, char* letter1, char* letter2);
unsigned int getunsignedint(int a, int b, char* str1, char* str2);
int reversBits(unsigned int number);
void displayBits(unsigned int number);

int main(void) {
	unsigned int input;

	input = getunsignedint(0, UINT_MAX, "Enter an unsigned integer number: ", "WRONG INPUT!\n\n");
	printf("\nBefore bits are reversed:\n\t\t");
	displayBits(input);
	printf("\nAfter bits are reversed:\n\t\t");
	displayBits(reversBits(input));
	printf("\n\n");
	return 0;
}
void inputname(char* arr, int n, char* letter1, char* letter2) {

	int judge;
	int i;
	do {
		judge = 0;
		printf("%s", letter1);
		for (i = 0; i < n; i++) {
			arr[i] = getchar();
			if (arr[i] == '\n') {
				arr[i] = NULL;
				judge = 1;
				break;
			}
		}
		if (judge == 0) {
			while (getchar() != '\n');
			printf("%s", letter2);
		}
	} while (judge == 0);
}
unsigned int getunsignedint(int a, int b, char* str1, char* str2) {
	unsigned long largeunint = 0;
	int judge = 1;
	int i;
	char* inputunint =(char*)malloc(11*sizeof(char));

	do {
		judge = 1;
		inputname(inputunint,11, str1, str2);
		for (i = 0; inputunint[i]; i++) if (inputunint[i] < '0' || inputunint[i] > '9') {
			printf("WRONG INPUT: input must be integer\n\n");
			judge = 0;
			break;
		}
		if (judge == 1) {
			for (i = 0; inputunint[i];i++) {
				largeunint *= 10;
				largeunint += inputunint[i]-'0';
			}
		}
		
		if (largeunint < a || largeunint > b) judge == 0;

	} while (judge == 0);

	return (unsigned int)largeunint;
}

void displayBits(unsigned int number) {
	unsigned int mask = 1 << 31;
	int i;
	printf("%u = ",number);
	for (i = 0; i < 32; i++) {

		if ((number&mask) == mask) printf("1");
		else printf("0");
		if ((i % 8) == 7)printf(" ");

		mask >>= 1;
	}
	printf("\n");
}
int reversBits(unsigned int number) {
	unsigned int reverse = 0;
	unsigned int mask = 1;
	int i;

	for (i = 0; i < 32;i++) {
		reverse *= 2;
		if ((number&mask) == mask) reverse += 1;
		mask <<= 1;
	}

	return reverse;
}
