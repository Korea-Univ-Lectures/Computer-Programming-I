// 5개의 정수 입력을 받아서 array에 저장한 후, 가장 큰 값을 찾는 프로그램

#include <stdio.h>

#define LIST_SIZE 5

int get_max(const int list[], int n);

int main()
{
	int i;
	int list[LIST_SIZE] = {0, };
	printf("Type %d integers : ", LIST_SIZE);
	for(i=0;i<LIST_SIZE;i++)
	{
		fflush(stdin);
		scanf("%d", list+i);
	}

	printf("The largest # : %d", get_max(list, LIST_SIZE));

	return 0;
}

int get_max(const int list[], /* input - list of n integers	*/
	int n)      /* input - number of list elements to examine	*/
{
      int i,
          cur_large;      /* largest value so far	*/

      /*  Initial array element is largest so far.	*/
      cur_large = list[0];

      /*  Compare each remaining list element to the largest so far;
          save the larger	*/
      for  (i = 1;  i < n;  ++i)
          if (list[i] > cur_large)
                cur_large = list[i];

      return (cur_large);
}

