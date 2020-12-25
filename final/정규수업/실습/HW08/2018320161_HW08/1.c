#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	char semi_ISBN[5];
	int page;
}book;

void inputname(char *arr, int n, char letter1, char letter2);
int getint(int a, int b, char str1, char str2);

int main(void) {
	int level = -1;
	int index = 1;
	int i;
	int judge = 0;
	book tmp;
	book * shelf = (book*)malloc(index * sizeof(book));
	book * fix = (book*)malloc(sizeof(book));
	book * bucket1 = (book*)malloc(sizeof(book));
	book * bucket2 = (book*)malloc(sizeof(book));
	strcpy(shelf->name, "Let¡¯s do it");
	strcpy(shelf->semi_ISBN, "4456");
	shelf->page = 36;
	while (1) {
		level = getint(1, 5, "----------- menu -----------\n1. Display my book(s)\n2. Add a book\n3. Delete a book\n4. Sort my books\n5. Exit\n----------------------------\nChoose a number : ", "\nWrong input! input must be in 1~5\n\n");
		switch (level) {
		case 1:
			printf("\nThere is %d book(s)\n\n", index);
			for (i = 0; i < index; i++) printf("%s (ISBN:%s), %d pages\n", (shelf + i)->name, (shelf + i)->semi_ISBN, (shelf + i)->page);
			printf("\n");
			break;

		case 2:
			index++;
			shelf = (book*)realloc(shelf, index * sizeof(book));
			inputname((shelf + index - 1)->name, 30, "Please enter the name: ", "WRONG INPUT: letter must smaller than 30\n\n");
			do {
				judge = 1;
				printf("semi_ISBN: ");
				for (i = 0; i < 4; i++) {
					(shelf + index - 1)->semi_ISBN[i] = getchar();
					if ((shelf + index - 1)->semi_ISBN[i]<'0' || (shelf + index - 1)->semi_ISBN[i]>'9') {
						if ((shelf + index - 1)->semi_ISBN[i] == '\n');
						else while (getchar() != '\n');
						judge = 0;
						break;
					}
				}
				if (judge == 1) {
					(shelf + index - 1)->semi_ISBN[4] = getchar();
					if ((shelf + index - 1)->semi_ISBN[4] == '\n')(shelf + index - 1)->semi_ISBN[4] = NULL;
					else {
						while (getchar() != '\n');
						judge = 0;
					}
				}
				if (judge == 0) printf("WRONG INPUT! ISBN should be 4 digits\n\n");
			} while (judge == 0);

			(shelf + index - 1)->page = getint(1, INT_MAX, "the number of page: ", "the number of page must be 1~INT_MAX\n\n");
			break;

		case 3:
			judge = 0;
			inputname(fix->name, 30, "Please enter the book name to be removed: ", "WRONG INPUT: letter must smaller than 30");
			for (i = 0; i < index; i++) {
				if (!strcmp((shelf + i)->name, fix->name)) {
					judge = 1;
					break;
				}
			}
			if (judge == 1) {
				for (; i < index; i++) {
					*(shelf + i) = *(shelf + i + 1);
				}
				index--;
				shelf = (book*)realloc(shelf, index * sizeof(book));
				printf("\n%s is removed from your bookshelf\n\n", fix->name);
				judge = 0;
			}
			else printf("\n%s is not in your bookshelf\n\n", fix->name);
			break;

		case 4:
			for (i = 0; i < index; i++) {
				int last = index;
				for (int j = 0; j < last; j++) {
					for (int k = 0; (shelf + i)->name[k]; k++) {
						if ((shelf + i)->name[k] >= 'A' && (shelf + i)->name[k] <= 'Z')
							bucket1->name[k] = (shelf + i)->name[k] - 'A' + 'a';
						else bucket1->name[k] = (shelf + i)->name[k];
					}
					for (int k = 0; (shelf + i + 1)->name[k]; k++) {
						if ((shelf + i + 1)->name[k] >= 'A' && (shelf + i + 1)->name[k] <= 'Z')
							bucket2->name[k] = (shelf + i + 1)->name[k] - 'A' + 'a';
						else bucket2->name[k] = (shelf + i + 1)->name[k];
					}
					if (strcmp(bucket1->name, bucket2->name) == 1) {
						tmp = *(shelf + i);
						*(shelf + i) = *(shelf + i + 1);
						*(shelf + i + 1) = tmp;
					}
				}
				last--;
			}
			printf("Bookshelf is alphabetically ordered\n");
			break;

		default:
			break;
		}
		if (level == 5) break;
	}
	return 0;
}
void inputname(char *arr, int n, char* letter1, char* letter2) {
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
int getint(int a, int b, char* str1, char* str2) {
	long largeint = 0;
	int judge = 1;
	char inputint[11];
	int i;

	do {
		inputname(inputint, 11, str1, str2);
		for (i = 0; inputint[i]; i++) if (inputint[i] < '0' || inputint[i] > '9') {
			printf("WRONG INPUT: input must be integer\n\n");
			judge = 0;
			break;
		}
		if (judge == 1) for (i = 0; inputint[i]; i++) {
			largeint *= 10;
			largeint += (inputint[i] - '0');
		}
		if (largeint < a || largeint > b) judge == 0;

	} while (judge == 0);
	return (int)largeint;
}
