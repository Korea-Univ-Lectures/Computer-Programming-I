#include <stdio.h>

void swap(int a, int b);
int main()
{
	int a, b;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	printf("before swap : a=%d, b=%d\n", a, b);
	swap(a, b);
	printf("after swap : a=%d, b=%d\n", a, b);

	return 0;
}

void swap(int a, int b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
	printf("in swap : a=%d, b=%d\n", a, b);
}