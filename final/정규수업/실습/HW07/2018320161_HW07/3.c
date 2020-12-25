#include <string.h>  
#include <stdio.h>  

char string[3][50] = {0};
char steps[] = " ,\t\n";
char count[12] = {0};
int num;
char *word;

int main(void)
{
	for (int i = 0; i < 3; i++) {
		printf("Enter the integer: ");
		gets_s(string[i]);
		word = strtok(string[i], steps);
		while (word != NULL)
		{
			num = strlen(word);
			if (num > 10) count[11]++;
			else count[num]++;
			word = strtok(NULL, steps);
		}
	}
	for (int i = 1; i <= 11;i++) {
		if(i==11){
			if (count[i] == 1) printf("1 word of length more than 10\n");
			else if (count[i] > 1) printf("%d words of length more than 10\n", count[i]);
		}
		else{
			if (count[i] == 1) printf("1 word of length %d\n", i);
			else if (count[i] > 1) printf("%d words of length %d\n", count[i], i);
		}
	}
}
