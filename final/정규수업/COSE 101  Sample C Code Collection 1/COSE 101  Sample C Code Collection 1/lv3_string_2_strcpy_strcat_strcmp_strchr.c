#include <stdio.h>
#include <string.h>
 
int main()
{
	char line1[100]={0, }, line2[100]={0, }, *sub_text;	 
	 int res;
     /* initialize string */ 
     strcpy(line1,"hello, I am a string;");
	 strcpy(line2,"hello, I am a string;");
     printf("Line1: %s\n", line1);
	 printf("Line2: %s\n", line2);
	 /* compare line1 with line2 */
	 res=strcmp(line1, line2);
	 if(res==0)
		printf("Line1 and Line2 are same.\n");
	 else
		 printf("Line1 and Line2 are different.\n", res);
     /* add to end of string */ 
     strcat(line1," what are you?");
     printf("Line1: %s\n", line1);
	 /* compare line1 with line2 again*/	 
	 res=strcmp(line1, line2);
	 if(res==0)
		printf("Line1 and Line2 are same.\n");
	 else
		 printf("Line1 and Line2 are different.\n", res);
     /* find length of string */ 
      /* strlen brings back    */
     /* length as type size_t */

     printf("Length of line1: %d\n", (int)strlen(line1));

     /* find occurence of substrings */ 
     if ( (sub_text = strchr ( line1, 'W' ) )!= NULL )
            printf("String starting with \"W\" ->%s\n", sub_text);
 
     if ( ( sub_text = strchr ( line1, 'w' ) )!= NULL )
            printf("String starting with \"w\" ->%s\n", sub_text);
 
     if ( ( sub_text = strchr ( sub_text, 'u' ) )!= NULL )
            printf("String starting with \"w\" ->%s\n", sub_text);
	
	 return 0;
}