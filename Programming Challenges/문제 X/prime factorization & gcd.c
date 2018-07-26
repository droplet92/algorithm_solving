#include <stdio.h>
#include <math.h>

/* 소인수분해 */
void prime_factorization(long x)
{
	long i;		/* 카운터 */
	long c;		/* 소인수분해해야 할 부분 */

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

/* p와 q의 최대공약수 */
long gcd(long p, long q, long *x, long *y)
{
	long x1, y1;		/* 이전 계수 */
	long g;				/* gcd(p, q)의 값 */

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