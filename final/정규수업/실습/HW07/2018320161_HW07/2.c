#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[3][50];
	int alpha[26] = {0};
	
	for (int i = 0; i < 3;i++) {
		printf("Enter three lines of text:");
		gets_s(arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 40&&arr[i][j]; j++) {
			if (arr[i][j] - 'A' >= 0 && arr[i][j] - 'Z' <= 0) alpha[arr[i][j] - 'A']++;
			else if (arr[i][j] - 'a' >= 0 && arr[i][j] - 'z' <= 0) alpha[arr[i][j] - 'a']++;
		}
	}

	printf("\nThe total occurances of characters:\n");

	for (int i = 0; i < 26; i++) {
		printf("%c: %2d\n",i+97, alpha[i]);
	}
	return 0;
}
