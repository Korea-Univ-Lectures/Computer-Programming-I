#include <stdio.h>

int main(void) {

	char first[] ="a";
	char second[] = "a";
	int hei = -1, spa=-1;
	int i, h, h_fix;

	printf("Printing character: ");
	scanf("%s",&first);
	printf("2nd Printing character: ");
	scanf("%s", &second);

	do  {
		printf("Enter the Height number: ");
		scanf("%d", &hei);
		if (hei < 3 || hei % 2 == 0) printf("Wrong input for height of diamond \n");
	} while (hei < 3 || hei % 2 == 0);

	do {
		printf("space(s) between characters: ");
		scanf("%d", &spa);
		if (spa<=0) printf("Wrong input for space(s) of diamond \n");
	} while (spa <= 0);

	h = hei / 2; h_fix = h;
	for (h = 0; h <= hei / 2; h++) {
		for (i = 2*h_fix*(spa +1)+2; i >= 0; i--) {
			if (i == 1 + (h_fix - h)*(spa + 1)|| i == 1 + (h_fix+ h)*(spa + 1))printf("%s",first);
			else printf("%s", second);
		}
		printf("\n");
	}

	h = h_fix-1; 
	for (h = h_fix - 1; h >= 0; h--) {
		for (i = 2 * h_fix*(spa + 1) + 2; i >= 0; i--) {
			if (i == 1 + (h_fix - h)*(spa + 1) || i == 1 + (h_fix + h)*(spa + 1))printf("%s", first);
			else printf("%s", second);
		}
		printf("\n");
	}

	return 0;
}