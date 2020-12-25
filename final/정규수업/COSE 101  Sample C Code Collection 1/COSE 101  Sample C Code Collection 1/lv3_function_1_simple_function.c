/*//////////////////////////////////////////////////////////////////////////////

	컴퓨터과학연습, 소프트웨어공학, 요구공학 세 과목의 점수를 입력 받아서 총점과 평균을 구한 후에 출력하는 프로그램을 작성한다. 
	입력 점수는 정수이며, 평균과 총점을 계산하는 함수는 따로 작성한다.
	평균은 소수점 2자리까지 출력한다.

//////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int calc_total(int cs, int se, int re)
{
	int total;
	total = cs + se + re;
	return total;
}

double calc_aver(int total)
{
	return (double)total/3;
}

int main(){
	int cs, se, re, total;			// cs : 컴퓨터과학연습, se: 소프트웨어공학, re: 요구공학
	double aver;
	printf("컴퓨터과학연습, 소프트웨어공학, 요구공학 점수를 입력하세요 : \n");
	scanf("%d %d %d", &cs, &se, &re);
	total = calc_total(cs, se, re);
	aver = calc_aver(total);
	
	printf("총점은 %d이고 평균은 %.2lf입니다.\n", total, aver);
	return 0;
}