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
	int i, j;		/* ī���� */
	int min;		/* �ּҰ��� �ε��� */

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
	int p[NPEOPLE];		/* �ٸ��� �ǳʴ� ��� */
	int t;				/* �׽�Ʈ ���̽� */
	int n;				/* �ٸ��� �ǳʴ� ��� �� */
	int i, j;			/* ī���� */

	scanf("%d", &t);
	for (i = 0; i < t; ++i)
	{
		getchar();	//����

		/* ���� �̿��� ���� ������ ���� */
		if (!scanf("%d", &n)) break;

		/* �ٸ��� �ǳʴ� ����� �ð� �Է� */
		for (j = 0; j < n; ++j) scanf("%d", &p[j]);

		/* �ð� ������ ���� */
		selection_sort(p, n);

		/* �ٸ� �ǳʱ� */
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