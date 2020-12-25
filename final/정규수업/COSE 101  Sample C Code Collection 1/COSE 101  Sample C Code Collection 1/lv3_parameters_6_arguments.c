#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int operand1, operand2, result;
	char op, name[80];
	if(argc<4) {
		printf("Arguments are not enough!\n");
		exit(1);
	}
	strcpy(name, argv[0]);
	operand1=atoi(argv[1]);
	op=argv[2][0];
	operand2=atoi(argv[3]);
	printf("The program : %s\n", name);
	switch(op) {
	case '+':
		result=operand1+operand2;
		break;
	case '-':
		result=operand1-operand2;
		break;
	case '*':
		result=operand1*operand2;
		break;
	case '/':
		result=operand1/operand2;
		break;
	case '%':
		result=operand1%operand2;
		break;
	}
	printf("The result is : %d\n", result);
	return 0;
}