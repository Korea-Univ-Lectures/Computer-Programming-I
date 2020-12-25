#include <stdio.h>

int main()
{
	char ch;
	ch = getchar();
	putchar(ch);
	ch = getchar();
	putchar(ch);

	return 0;
	
	/*
	Try "H[enter]i[enter]".
	And try "Hello[enter]".
	In the second case, console asks you to type only once even though the code has two getchar() instructions.
	Before you have the chance of typing, the second getchar() instruction encounter with the second character in the word that is stored in a buffer.  
	*/
}