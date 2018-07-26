#include <stdio.h>
#include <math.h>

/* ���μ����� */
void prime_factorization(long x)
{
	long i;		/* ī���� */
	long c;		/* ���μ������ؾ� �� �κ� */

	c = x;
	while ((c % 2) == 0)
	{
		putc('2', stdout);
		c /= 2;
	}

	i = 3;
	while (i <= (sqrt(c) + 1))
	{
		if ((c%i) == 0)
		{
			printf("%ld\n", i);
			c /= i;
		}
		else
			i += 2;
	}
	if (c > 1) printf("%ld\n", c);
}

/* p�� q�� �ִ����� */
long gcd(long p, long q, long *x, long *y)
{
	long x1, y1;		/* ���� ��� */
	long g;				/* gcd(p, q)�� �� */

	if (q > p) return gcd(q, p, y, x);

	if (q == 0)
	{
		*x = 1;
		*y = 0;
		return p;
	}

	g = gcd(q, p%q, &x1, &y1);

	*x = y1;
	*y = x1 - (floor(p / q)*y1);

	return g;
}