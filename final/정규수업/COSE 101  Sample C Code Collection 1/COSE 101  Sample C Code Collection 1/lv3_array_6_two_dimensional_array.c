/*//////////////////////////////////////////////////////////////////////////////

 5*5 ������ �迭�� ���� ������ ä�� ��, �밢��, ��ﰢ(upper triangular), �ϻﰢ(lower triangular)�� ���� ���

//////////////////////////////////////////////////////////////////////////////*/


#include <stdio.h>
#include <stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include <time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 

int main(){	
	int num[5][5];
	int cols, rows;
	int i, j;
	int diagonal=0, upper=0, lower=0;
	
	srand(time(0));
	/* 5*5 ������ �迭�� �� ä��� */
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			num[i][j] = rand() % 11;	// 0~10 ������ ���� �ѹ� ����
		}
	}
	cols = sizeof(num)/sizeof(num[0]);
	rows = sizeof(num[0])/sizeof(num[0][0]);

	for(i=0;i<cols;i++){
		printf("%d�� �� : ", i);
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
