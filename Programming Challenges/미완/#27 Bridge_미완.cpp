#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPEOPLE	1000

void swap(int *lhs, int *rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void selection_sort(int s[], int len)
{
	int i, j;		/* 카운터 */
	int min;		/* 최소값의 인덱스 */

	for (i = 0; i < len; ++i)
	{
		min = i;
		for (j = i + 1; j < len; ++j)
		{
			if (s[j] < s[min]) min = j;
		}
		swap(&s[i], &s[min]);
	}
}

void CrossBridge(int p[], int len)
{
	int sum;
}

int main()
{
	int p[NPEOPLE];		/* 다리를 건너는 사람 */
	int t;				/* 테스트 케이스 */
	int n;				/* 다리를 건너는 사람 수 */
	int i, j;			/* 카운터 */

	scanf("%d", &t);
	for (i = 0; i < t; ++i)
	{
		getchar();	//빈줄

		/* 숫자 이외의 것이 들어오면 종료 */
		if (!scanf("%d", &n)) break;

		/* 다리를 건너는 사람의 시간 입력 */
		for (j = 0; j < n; ++j) scanf("%d", &p[j]);

		/* 시간 순서로 정렬 */
		selection_sort(p, n);

		/* 다리 건너기 */
		CrossBridge(p, n);
	}
	return 0;
}

/*
1

4
1
2
5
10
*/