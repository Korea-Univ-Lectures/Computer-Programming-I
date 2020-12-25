#include <stdio.h>
#include <string.h>

void reverse(char s[]);
int main()
{
	char text[80]={0, };
	gets(text);
	printf("string is %s\n", text);
	reverse(text);
	printf("string is %s\n", text);
}

void reverse(char s[])
{	
	int c, i, j;
    
	for (i=0, j=strlen(s)-1; i < j;i++, j--)
	{
		c = s[i];
		s[i] = s [j];
		s[j] = c;
	}
}
