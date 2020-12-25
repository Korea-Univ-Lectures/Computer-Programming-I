#include <stdio.h>

int main()
{
	float r1, r2;
	int result1, result2;
	
	r1 = 3.4;
	r2 = 2.1;
	
	result1 = r1 * r2; // 3.4 * 2.1 = 7.14 => 7
	result2 = (int)r1 * (int)r2; // 3 * 2 = 6 => 6
	
	printf("result1 = %d\n", result1);
	printf("result2 = %d\n", result2);

	return 0;
}