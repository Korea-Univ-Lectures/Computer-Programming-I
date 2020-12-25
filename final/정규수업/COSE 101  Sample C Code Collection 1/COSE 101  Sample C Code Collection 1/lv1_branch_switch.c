#include <stdio.h>
main()
{
	enum People1 {Alex_girl=0,    Tracy,  Kristian} Girls;
	enum People2 {William=0, Martin, Alex}     Boys;
	/*     A      A
	|      |
	|      |
	|      -------  list of aliases.
	--------------  Enumeration tag. */
	
	Boys = Martin;
	switch (Boys)
	{
		case William:
			puts("William");
			break;
		
		case Martin:
			puts("Martin");
			break;
		
		case Alex:
			puts("Alex");
			break;
		
		default:
			break;
	}
}
