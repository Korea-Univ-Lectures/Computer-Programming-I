#include <stdio.h>

int add(char *str1, char *str2);

int main(void) {

	char string1[80];
	char string2[80];


	printf("Enter one string:");
	gets_s(string1);
	printf("Enter two string:");
	gets_s(string2);

	add(string1, string2);

	return 0;
}

int add(char *str1, char *str2) {
	int j = 0;
	int k = 0;

	while (str1[j]) {
		j++;
	}
	str1[j] = NULL;

	while (str2[k]) {
		str1[j+k] = str2[k];
		k++;
	}
	str1[j + k] = NULL;

	printf("%s",str1);

	return 1;
}