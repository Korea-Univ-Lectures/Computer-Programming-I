#include <stdio.h>
#define LIST_SIZE 2

int main()
{
	int list[LIST_SIZE]={4,6};   /* array declaration   */
	int count=0;

	for (count=0;count<LIST_SIZE;count++) 
		printf("i starts out life as %d.\n", list[count]);

	++*list;    /* Add 1 to the first element in 
        the array   */
	++*(list+1);    /* And the second element */

	for (count=0;count<LIST_SIZE;count++)
		printf("            i is now %d.\n", list[count]);

	return 0;
}
