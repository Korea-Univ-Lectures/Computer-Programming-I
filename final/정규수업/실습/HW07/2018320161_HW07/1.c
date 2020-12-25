#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[10][20] = {0};
	char temp[20];
	for (int i = 0; i < 10; i++) {
		printf("Enter a string:");
		scanf("%s", &arr[i]);
		if (!(arr[i][0] >= 'A'&&arr[i][0] <= 'Z')) { 
			printf("WRONG INPUT: head letter should be Large Alphabet\n\n");
			i--; 
		}
		else { 
			for (int j = 1; j < 20; j++) {
				if ((!(arr[i][j] >= 'a'&&arr[i][j] <= 'z'))&&arr[i][j]) { 
					printf("WRONG INPUT: Input should be small Alphabet except head letter\n\n");
					i--;
					break;
				}
			}
		}
	}
	for (int i = 9; i >0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(arr[j], arr[j + 1]) == 1) {
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
	printf("\nThe strings in sorted order are:\n");
	for (int i = 0; i < 10;i++) { 
		printf("%s\n", arr[i]); 
	}
	return 0;
}