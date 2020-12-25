#include <stdio.h>
#include <string.h>

main()
{
	char buff[80];   /* Input buffer.  */
	
	 /* Get data from the keyboard. */
	printf("\nplease enter text => ");
	
	gets(buff);
	
	printf("\nlength is %d #%s#\n", strlen(buff), buff);
	
	
	/*
	gets() instruction is dedicated to deal with the stdin.
	fgets(), a versitle stream reader, also can be used to read stdin if you assigned stdin as a input stream.
	However, note that the fgets() normally used as a file stream reader.
	*/
	
	 /* Get data from the keyboard. */
	printf("\nplease enter text => ");
	
	fgets(buff, sizeof(buff), stdin);
	
	printf("\nlength is %d #%s#\n\n",strlen(buff),  buff);
}
