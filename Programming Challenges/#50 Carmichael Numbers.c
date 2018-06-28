#include <stdio.h>
#include <math.h>

typedef enum { False, True } Bool;

Bool isPrimeNumber(int n);
Bool isFermatNumber(int n, int a);
void CarmichaelTest(int n);

int pow_mod(int a, int n)
{
	int temp;	/* 결과값 */
	int i;		/* 카운터 */

	temp = (a % n);
	for (i = 1; i < n; ++i)
		temp = (a*temp) % n;

	return temp;
}

int main()
{
	int n;		/* 입력받은 정수 */

	while (scanf("%d", &n) && n != 0)
	{
		if (isPrimeNumber(n))
			printf("%d is normal.\n", n);
		else
			CarmichaelTest(n);
	}
	return 0;
}

Bool isPrimeNumber(int n)
{
	int root;	/* root n을 내림한 정수 */
	int i;		/* 카운터 */

	root = (int)sqrt(n);
	for (i = 2; i <= root; ++i)
	{
		if (n%i == 0) return False;
	}
	return True;
}

Bool isFermatNumber(int a, int n)
{
	int i;		/* 카운터 */

	/* 제곱의 모듈러 계산 */
	if (pow_mod(a, n) == a) return True;
	return False;
}

void CarmichaelTest(int n)
{
	int i;		/* 카운터 */

	for (i = 2; i < n; ++i)
	{
		if (!isFermatNumber(i, n))
		{
			printf("%d is normal.\n", n);
			return;
		}
	}
	printf("The number %d is a Carmichael number.\n", n);
}

/*
1729
17
561
1109
431
0
*/