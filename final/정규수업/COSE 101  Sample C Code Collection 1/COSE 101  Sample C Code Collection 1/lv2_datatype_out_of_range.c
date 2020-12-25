#include <stdio.h>

int main()
{
	short s;
	long l;
	unsigned u;
	
	printf("Enter a short number : ");
	scanf("%hd", &s);	//Try 32767 and 32768
	
	printf("Enter a long number : ");
	scanf("%ld", &l);
	
	printf("Enter an unsigned number : ");
	scanf("%u", &u);	//Try 65535, 65536, and -1.
	
	printf("\n%hd %ld %u \n", s, l, u);
	return 0;
}