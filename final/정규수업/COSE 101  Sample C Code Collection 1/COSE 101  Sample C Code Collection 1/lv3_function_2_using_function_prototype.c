/*//////////////////////////////////////////////////////////////////////////////
	<윤년 계산법>
	1. 윤년은 4년마다 돌아온다. 
	2. 100의 배수 해는 윤년이 아니다.
	3. 단, 400의 배수 해는 윤년이다.
	위의 윤년 계산법을 이용하여 연도를 입력받아 윤년인지 아닌지 출력하는 프로그램을 작성하시오.

//////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int calc_leap(int y);

int main(){
	int year, res, scanRes = 0;
	
	while(scanRes!=1){
		fflush(stdin);						// stdin buffer를 비워줌
		printf("년도를 입력하시오 : ");
		scanRes = scanf("%d", &year);		// 잘못된 입력을 검사
	}
	res = calc_leap(year);
	if(res==0){
		printf("%d년은 평년(Common year)입니다.\n", year);
	}
	else{
		printf("%d년은 윤년(Leap year)입니다.\n", year);
	}	
	return 0;
}

int calc_leap(int y){
	int res;				//res : 0 -> 평년, 1 -> 윤년

	if(y%4!=0){				//4로 나누어 떨어지지 않으면 
		res = 0;			//평년
	}
	else if(y%100!=0){		//4로 나누어 떨어지고 100으로 나누어 떨어지지 않으면
		res = 1;			//윤년
	}
	else if(y%400!=0){		//4, 100으로 나누어 떨어지고 400으로 나누어 떨어지지 않으면
		res = 0;			//평년
	}
	else{					//4, 100, 400으로 나누어 떨어지면
		res = 1;			//윤년
	}
	return res;
}
