#include <stdio.h>

int equal(char value1[], char value[]);

int sizechar(char value[]);

int main(void) {
	char value1[80];
	char value2[80];

	printf("Enter the string: ");
	gets_s(value1);

	equal(value1, value2);

	printf("%s",value1);

	return 0;
}

int equal(char value1[],char value2[])
{
	int start = 0, end = sizechar(value1)-1;
	bool judge = 1;
	int i = 0,j=0;

	while (value1[i]) {
		if (value1[start + i] != value1[end + i]) {
			judge = 0;
			break;
		}
		i++;
	}

	if (judge) printf("%s is palindrome\n", value1);
	else {
		printf("%s is not palindrome\n", value1);
		i = 0;
		while (value1[i]) {
			value2[i] = value1[i];
			i++;
		}
		i--;
		while (j<=end) {
			value2[i+j] = value2[i-j];
			j++;
		}
		value2[i + j] = '\0';
		printf("use %s to build %s\n", value1, value2);
	}

	return judge;
}

int sizechar(char value[]) {
	int i = 0;
	while (value[i]) i++;
	return i;
}
