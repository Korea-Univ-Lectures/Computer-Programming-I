#include <stdio.h>

int main()
{
	char str[]="0123456789"; 
	printf("The str : %s\n", str); 
	printf("The 2nd element of the str : %c\n", str[1]);
	printf("The address of 2nd element : %x\n", str+1);
	printf("The # of str's elements : %d\n", sizeof(str));
	*(str+1) = 'x';
	printf("The str : %s\n", str); 
     
	return 0;
}
