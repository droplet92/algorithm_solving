#include <stdio.h>

void swap(int*, int*);
int partition(int[], int, int);

/* 정렬 함수 */

void selection_sort(int s[], int n)
{
	int i, j;		/* 카운터 */
	int min;		/* 최소값의 인덱스 */

	for (i = 0; i < n; ++i)
	{
		min = i;
		for (j = i + 1; j < n; ++j)
			if (s[j] < s[min]) min = j;
		swap(&s[i], &s[min]);
	}
}

void insertion_sort(int s[], int n)
{
	int i, j;		/* 카운터 */

	for (i = 1; i < n; ++i)
	{
		j = i;
		while ((j > 0) && (s[j] < s[j - 1]))
		{
			swap(&s[j], &s[j - 1]);
			j = j - 1;
		}
	}
}

void quicksort(int s[], int l, int h)
{
	int p;			/* 분할의 인덱스 */

	if ((h - l) > 0)
	{
		p = partition(s, l, h);
		quicksort(s, l, p - 1);
		quicksort(s, p + 1, h);
	}
}

/* 정렬에 사용되는 함수 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int s[], int l, int h)
{
	int i;			/* 카운터 */
	int p;			/* 피벗 원소의 인덱스 */
	int firsthigh;	/* 피벗을 위한 디바이더 위치 */

	p = h;
	firsthigh = l;
	for (i = l; i < h; ++i)
	{
		if (s[i] < s[p])
		{
			swap(&s[i], &s[firsthigh]);
			++firsthigh;
		}
	}
	swap(&s[p], &s[firsthigh]);
	return firsthigh;
}