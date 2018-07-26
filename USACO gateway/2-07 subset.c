/*
ID: lhs14381
LANG: C
TASK: subset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NMAX	40
#define NSUM	391

FILE *in, *out;
int n, sum;
uint32_t dp[NMAX][NSUM];

void main()
{
	in = fopen("subset.in", "r");
	out = fopen("subset.out", "w");

	/* get inputs */
	fscanf(in, "%d", &n);

	/* algorithms */
	sum = n * (n + 1) / 2;
	int i, j;

	if (sum % 2)
		fprintf(out, "0\n");
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= (sum / 2); j++)
			{
				if (j == 0)
					dp[i][j] = 1;
				else if (i == 0)
					dp[i][j] = 0;
				else if (j < i)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j]);
			}
		}
		fprintf(out, "%d\n", (int)(dp[n][sum / 2] / 2));
	}

	/* exit */
	exit(0);
}