#include <stdio.h>
main()
{
	int i = 0; 
	int j = 0;
	
	puts("\n\tDemo 3");
	if ( (i++ == 1) && (j++ == 1)) puts("Some text");
	
	/* Will i and j get incremented? The answer is NO! Because 
	* the expression in the left of '&&' resolves to false the 
	* compiler does NOT execute the expression on the right and 
	* so 'j' does not get executed!!!!! */
	
	
	printf("\t%d %d\n",i, j);    /* O/P 1 0 */
}