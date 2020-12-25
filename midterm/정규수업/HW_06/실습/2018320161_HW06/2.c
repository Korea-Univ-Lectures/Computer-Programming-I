#include <stdio.h>

int compare(char *str1, char *str2);

int main(void) {

	char string1[80];
	char string2[80];

	while (1) {
		printf("Enter one string:");
		gets_s(string1);
		printf("Enter the other string:");
		gets_s(string2);
		if (compare(string1, string2))
			printf("%s and %s are equal\n\n",string1, string2);
		else printf("%s and %s are not equal\n\n", string1, string2);
	}

	return 0;
}

int compare(char *str1, char *str2) {
	int j = 0;

	while (str1[j]) {
		if (str2[j] != str1[j]) return 0;
		j++;
	}

	return 1;
}