#include <stdio.h>
main()
{

	/*
	* ++i - i incremented before i is used.
	* --i - i decremented before i is used.
	* j++ - j is incremented AFTER j has been used. 
	* j-- - j is decremented AFTER j has been used. 
	*/
	
	int i=1,j=1;
	
	puts("\tDemo 1");
	printf("\t%d %d\n",++i, j++);   /* O/P  2 1 */
	printf("\t%d %d\n",i, j);    /* O/P  2 2 */
	
	i=1;j=1;
	
	puts("\n\tDemo 2");
	printf("\t%d \n",i=j++);    /* O/P  1 */
	printf("\t%d \n",i=++j);    /* O/P  3 */

}