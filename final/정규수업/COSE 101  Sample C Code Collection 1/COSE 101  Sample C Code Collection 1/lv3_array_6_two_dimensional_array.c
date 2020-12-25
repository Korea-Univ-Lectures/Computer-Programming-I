/*//////////////////////////////////////////////////////////////////////////////

 5*5 이차원 배열을 랜덤 값으로 채운 후, 대각선, 상삼각(upper triangular), 하삼각(lower triangular)의 합을 출력

//////////////////////////////////////////////////////////////////////////////*/


#include <stdio.h>
#include <stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include <time.h> // time() 함수를 사용하기 위해서 인클루드 함 

int main(){	
	int num[5][5];
	int cols, rows;
	int i, j;
	int diagonal=0, upper=0, lower=0;
	
	srand(time(0));
	/* 5*5 이차원 배열의 값 채우기 */
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			num[i][j] = rand() % 11;	// 0~10 사이의 랜덤 넘버 생성
		}
	}
	cols = sizeof(num)/sizeof(num[0]);
	rows = sizeof(num[0])/sizeof(num[0][0]);

	for(i=0;i<cols;i++){
		printf("%d번 행 : ", i);
		for(j=0;j<rows;j++){
			printf("%3d", num[i][j]);
			if(j>i){
				upper+=num[i][j];
			}
			else if(j<i){
				lower+=num[i][j];
			}
			else{
				diagonal+=num[i][j];
				upper+=num[i][j];
				lower+=num[i][j];
			}
		}
		printf("\n");
	}
	printf("diagonal = %d\n", diagonal);
	printf("upper = %d\n", upper);
	printf("lower = %d\n", lower);
	
	return 0;
}
