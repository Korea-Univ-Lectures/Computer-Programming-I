#include <stdio.h>

int main(void) {
	printf("Enter pairs of item numbers and quantities\n");
	printf("Enter -1 for the item number to end input\n");

	int pro = 0, quan;
	float sum = 0;

	do {
		scanf_s("%d", &pro);
		if (pro == -1) break;

		scanf_s("%d", &quan);
		switch (pro) {

		case 1:
			sum += 2.98*quan;
			break;
		case 2:
			sum += 4.50*quan;
			break;
		case 3:
			sum += 9.98*quan;
			break;
		case 4:
			sum += 4.49*quan;
			break;
		case 5:
			sum += 6.87*quan;
			break;
		default:
			printf("Invaild product code:%d\n	    Quantity:%d\n", pro, quan);
			break;
		}

	} while (pro != -1);

	printf("The total retail value was %.2f\n", sum);

	return 0;
}