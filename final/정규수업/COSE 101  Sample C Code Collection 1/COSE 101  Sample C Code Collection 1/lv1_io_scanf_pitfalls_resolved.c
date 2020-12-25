#include <stdio.h>

int main()
{
	int a, b;
	char op;

	printf("Enter expression : ");
	scanf("%d %c %d", &a, &op, &b);
	printf("%d %c %d = %d\n", a, op, b, a+b);

	return 0;
	
	/*
	Although scanf function normaly dismisses blank characters such as [enter], %c with scanf forces to store every key you typed. 
	Try "10+20[enter]". a=10, op='+', b=20
	and try "10[enter]+[enter]20[enter]". a=10, op=[enter], b='+'
	
	To avoid this behavior of scanf, place spaces between arguments.
	ex) scanf("%d %c %d", &a, &op, &b);
	*/
}