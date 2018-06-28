#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN	9
#define MAXNUM	4

typedef enum { False, True } Bool;

Bool isPrimeNumber(int n)
{
	int root = (int)sqrt(n);
	int i;

	for (i = 2; i <= root; ++i)
		if (n%i == 0) return False;

	return True;
}

int MaxPrimeNumber(int n)
{
	int i;

	for (i = n; i > 1; --i)
		if (isPrimeNumber(i)) return i;

	return -1;
}

void DivideFour(int n)
{
	int arr[MAXNUM];
	int temp;
	int i;

	/* 최소 숫자는 8 */
	if (n < 8)
	{
		puts("Imposible.");
		return;
	}
	temp = n;

	/* 소수 4개로 나누기 */
	for (i = MAXNUM; i > 0; --i)
	{
		if (temp - (i * 2) < 0)
		{
			puts("Imposible.");
			return;
		}
		arr[MAXNUM - i] = MaxPrimeNumber(temp - ((i - 1) * 2));
		temp -= arr[MAXNUM - i];
	}

	/* 결과 출력 */
	for (i = 0; i < MAXNUM; ++i)
		printf("%d ", arr[i]);
	puts("");
}

int main()
{
	int n;
	char temp[MAXLEN];

	while (fgets(temp, MAXLEN, stdin))
	{
		temp[strlen(temp) - 1] = 0;
		n = atoi(temp);

		DivideFour(n);
	}
	return 0;
}

/*
24
36
46
*/