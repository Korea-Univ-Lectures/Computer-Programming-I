/*//////////////////////////////////////////////////////////////////////////////

	��ǻ�Ͱ��п���, ����Ʈ�������, �䱸���� �� ������ ������ �Է� �޾Ƽ� ������ ����� ���� �Ŀ� ����ϴ� ���α׷��� �ۼ��Ѵ�. 
	�Է� ������ �����̸�, ��հ� ������ ����ϴ� �Լ��� ���� �ۼ��Ѵ�.
	����� �Ҽ��� 2�ڸ����� ����Ѵ�.

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
	int cs, se, re, total;			// cs : ��ǻ�Ͱ��п���, se: ����Ʈ�������, re: �䱸����
	double aver;
	printf("��ǻ�Ͱ��п���, ����Ʈ�������, �䱸���� ������ �Է��ϼ��� : \n");
	scanf("%d %d %d", &cs, &se, &re);
	total = calc_total(cs, se, re);
	aver = calc_aver(total);
	
	printf("������ %d�̰� ����� %.2lf�Դϴ�.\n", total, aver);
	return 0;
}