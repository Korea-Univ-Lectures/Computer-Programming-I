#include <stdio.h>

static int reverse=0;
	
void recurse(int value) {

	if (value>0) {
		reverse*=10;
		reverse+=value%10;
		recurse(value/10);
	}

}

int main() {
	int value; 

	
	printf("Enter integer:");
	scanf("%d",&value);
	
	printf("integer is %d",value);
	recurse(value);
	printf("integer is %d", reverse);
	
	return 0;
}
