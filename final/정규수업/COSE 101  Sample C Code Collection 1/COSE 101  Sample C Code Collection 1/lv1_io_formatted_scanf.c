#include <stdio.h>

int main ()
{
	char str [80];
	int i;
	
	printf ("Enter your family name: ");
	
	// %[][][]s
	scanf ("%s",str);  
	printf ("Enter your age: ");
	
	// %[][][]d
	scanf ("%d",&i);
	printf ("Mr. %s , %d years old.\n",str,i);
	printf ("Enter a hexadecimal number: ");
	
	// %[][][]x
	scanf ("%x",&i);
	printf ("You have entered %#x (%d).\n",i,i);
  
  
	﻿float x = 0;
	char ch = '*';
	
	// %[*][][]f so on, and so on.
	scanf("%*f %d %*c",&i);
	
	printf("%f %d %c",x,i,ch);
  
  return 0;
}