#include <stdio.h>

int copy(char *str1, char *str2);

int main(void) {

	char string1[80];
	char string2[80];

	printf("Enter your string that you want to copy:");
	gets_s(string1);

	copy(string1, string2);

	printf("original:%s\n", string1);
	printf("your copy:%s\n", string2);

	return 0;
}

int copy(char *str1, char *str2) {
	int j = 0;

	for (j = 0; str1[j];j++) {
		str2[j] = str1[j];
	}
	str2[j] = NULL;




	return 1;
}