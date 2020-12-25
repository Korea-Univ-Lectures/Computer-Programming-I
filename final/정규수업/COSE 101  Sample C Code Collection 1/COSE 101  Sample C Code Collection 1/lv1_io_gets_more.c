#include <stdio.h>
#include <stdlib.h>

main()
{
	char data[100];
	double num1, num2;
	
	printf(" Please enter a number ==> " );
	gets(data);
	//atof: array to float
	num1 = atof(data);
	
	printf(" Please enter a number ==> " );
	gets(data);
	num2 = atof(data);
	
	 /* Stop a divide by zero with
	  * the goto statement.  */
	if ( num2 == 0.0 ) goto end_prog;
	
	printf(" %4.2f divided by %4.2f is %4.2f\n", num1, num2, num1/num2);
	
	//label
	end_prog:
	printf(" Program ended\n");
 
}