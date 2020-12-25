#include <stdio.h>

int ulcase(int a);

int main(void) {

	char input;
	int a = 0, judge = 2;

	while (1) {
		printf("Printing character: ");
		gets(input);
		a = input;
		if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) break;
		
	}

	judge = ulcase(a);
	if (judge == 1) printf("%c: Uppercase\n", a);
	else printf("%c: Lowercase\n", a);

	return 0;
}

int ulcase(int a) {
	if (a >= 65 && a <= 90) return 1;
	else return 0;
}
