/*
ID: lhs14381
LANG: C
TASK: nocows
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NODES	200
#define LEVELS	100
#define MOD		9901

static FILE *in, *out;
int n, k;
int cache[NODES][LEVELS];

void algorithm()
{
	int i, j, l;

	cache[1][1] = 1;
	cache[3][2] = 1;
	cache[5][3] = 2;

	for (i = 7; i <= n; i += 2)
	{
		for (j = ceil(log2(i + 1)); j <= k && j <= (i + 1) / 2; j++)
		{
			cache[i][j] += cache[i - 2][j - 1];
			cache[i][j] += cache[i - 2][j];
			cache[i][j] %= MOD;
		}
	}
}

void main()
{
	in = fopen("nocows.in", "r");
	out = fopen("nocows.out", "w");

	/* gets data */
	fscanf(in, "%d %d", &n, &k);

	/* algorithm */
	algorithm();

	/* prints */
	fprintf(out, "%d\n", cache[n][k]);

	/* exit */
	exit(0);
}