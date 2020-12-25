
#include <stdio.h>

main ()

{ 
	int result;
	
	printf("Type in exam result");
	scanf ("%d",&result);
	
	if (result < 10)
	{
		printf ("That is poor");
	}
	
	else
	
	{
		if (result > 20)
		{
			printf ("You have passed.");
		}
		
		else		
		{
			if (result > 70)
			{
				printf ("You got an A!");
			}
		}
	}
}