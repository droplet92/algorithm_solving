#include <stdio.h>
#include <stdlib.h>

#define abs(val)	(val) > 0 ? (val) : ((val) * (-1))

int Min(int diff)
{
	int cnt, val;	/* cnt는 i와 함께 증가, val은 결과값 */
	int i, j;		/* 카운터 */

	cnt = 1;
	val = 1;
	i = 1;

	while (i < INT_MAX)
	{
		for (j = i; j < (i + cnt); ++j)
			if (diff == j) return val;

		++val;

		for (j = (i + cnt); j < (i + cnt * 2); ++j)
			if (diff == j) return val;

		++val;
		++cnt;
		i = j;
	}
}

int main()
{
	int n;		/* 테스트 케이스 */
	int x, y;	/* x -> y 이동 */
	int i;		/* 카운터 */

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", Min(abs(y - x)));
	}
	return 0;
}