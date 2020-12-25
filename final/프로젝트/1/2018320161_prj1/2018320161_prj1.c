#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand((unsigned)time(NULL));
	int value = -1, a = 0, b = 1, c, awn, time, score = 0;
	clock_t start, end;

	while(1){
		printf("¦£---------------------------¦¤\n");
		printf("¦¢ Arithmetic Operation Game ¦¢\n");
		printf("¦¦---------------------------¦¥\n");
		printf("\n");
		for (int i = 1; i < 11; i++) {
			printf("  [%2d] Stage %d\n", i, i);
		}
		printf("  [11] Exit\n");
		printf("\n");
		do {
			printf(">>");
			scanf("%d", &value);
			if (value < 1 || value > 11) {
				printf("Wrong input! input must be in 1~11\n\n");
				while (getchar() != '\n');
			}
			else if (getchar() == 10);
			else {
				printf("Wrong input! input must be in 1~11\n\n");
				value = 0;
				while (getchar() != '\n');
			}
		} while (value < 1 || value > 11);
		if (value == 11) break;
		
		system("cls");
		printf("Stage %d, Answer the question in %d seconds\n", value, 15 - value);
		for (int i = 1; i < 11; i++) {
			int kind = rand() % 4 + 1;
			a = rand() % (6 + 4 * value) + 1;
			b = rand() % (6 + (4 * value)) + 1;
			switch (kind) {
			case 1:
				c = a + b;
				printf("[Q %d] %d + %d = ", i, a, b);
				break;
			case 2:
				do {
					a = rand() % (6 + (4 * value)) + 1;
					b = rand() % (6 + (4 * value)) + 1;
				} while (a < b);
				c = a - b;
				printf("[Q %d] %d - %d = ", i, a, b);
				break;
			case 3:
				c = a * b;
				printf("[Q %d] %d * %d = ",i, a, b);
				break;
			case 4:
				do {
					a = rand() % (6 + (4 * value)) + 1;
					b = rand() % (6 + (4 * value)) + 1;
				} while (a < b || a % b != 0);
				c = a / b;

				printf("[Q %d] %d / %d = ", i, a, b);
				break;
			}
			start = clock();
			scanf("%d", &awn);
			end = clock();
			time = (int)(end - start) / CLOCKS_PER_SEC;
		
			if (time> 15 - value)printf("\t\t\t\t\t\tTIME_OUT: It took %d seconds\n", time);
			else if (getchar() != 10) { 
				printf("\t\t\t\t\t\tWORNG: It was %d\n", c);
				while (getchar() != '\n');
			}
			else if (c != awn) printf("\t\t\t\t\t\tWORNG: It was %d\n", c);
			else {
				printf("\t\t\t\t\t\tCORRECT: It took %d seconds\n", time);
				score += 10;
			}
		}
		printf("\t\t\tSCORE:%d\n", score);
		score = 0;
		system("pause");
		system("cls");
		value = -1;
	}
	system("cls");
	return 0;
}
