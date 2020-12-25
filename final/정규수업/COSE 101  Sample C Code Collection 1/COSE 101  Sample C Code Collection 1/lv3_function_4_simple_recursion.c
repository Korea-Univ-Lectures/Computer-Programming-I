/*//////////////////////////////////////////////////////////////////////////////
	거듭제곱 구하기
	
	* 이 프로그램은 오버플로우가 발생할 가능성이 높습니다.
//////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int pow_sum(int b, int e);

int main(){
	int b, e;
	printf("Enter the base : ");
	scanf("%d", &b);
	printf("Enter the exponential : ");
	scanf("%d", &e);

	printf("The result of %d^%d is %d\n", b, e, pow_sum(b, e));
	
	return 0;
}

int pow_sum(int b, int e){
	if(b!=0){
		if(e==0){
			return 1;
		}
		else{
			return b*pow_sum(b, e-1);
		}
	}
	else if(b==0){
		return 0;
	}
}