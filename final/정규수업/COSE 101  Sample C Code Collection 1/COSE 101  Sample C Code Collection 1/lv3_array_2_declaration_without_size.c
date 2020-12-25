/*
	array 값의 합과 평균을 출력
	(배열의 크기를 생략하고 선언하는 예제
	선언한 배열의 크기를 구하는 과정 포함)
*/

#include <stdio.h>

int main()
{
	int list[] = {78, 54, 32, 99, 100, 95, 88, 82};
	int size = sizeof(list)/sizeof(int);
	int sum=0, i=0;
	double aver=0;

	for(i=0;i<size;i++)
	{
		sum+=list[i];
	}
	aver=(double)aver/size;

	printf("The size of the array : %d\n", size);
	printf("The sum of the list : %d\n", sum);
	printf("The average of the list : %.2lf\n", aver);

	return 0;
}