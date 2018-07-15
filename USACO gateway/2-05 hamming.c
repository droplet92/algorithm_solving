/*
ID: lhs14381
LANG: C
TASK: hamming
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX		65
#define BMAX		9
#define DECIMAL_MAX	0x100

int answer[NMAX];
int dist[DECIMAL_MAX][DECIMAL_MAX];
int n, b, d, maxval;
FILE *in, *out;

int hdistance(int a, int b)
{
	int comp = a ^ b;
	int distance = 0;

	for (int e = 1; (comp >= e && e <= 0x80); e <<= 1)
	{
		if ((comp & e) == e)
			++distance;
	}
	return distance;
}

void generate(int stage)
{
	if (stage == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (i % 10 == 9 || i == (n - 1))
				fprintf(out, "%d\n", answer[i]);
			else
				fprintf(out, "%d ", answer[i]);
		}
		exit(0);
	}
	else
	{
		int i, j;
		for (i = (answer[stage - 1] + 1); i < maxval; i++)
		{
			for (j = 0; j < stage; j++)
			{
				if (dist[answer[j]][i] < d)
					goto NEXT;
			}
			answer[stage] = i;
			generate(stage + 1);
		NEXT:
			;
		}
	}
}

void main()
{
	in = fopen("hamming.in", "r");
	out = fopen("hamming.out", "w");

	/* get inputs */
	fscanf(in, "%d %d %d", &n, &b, &d);
	maxval = (1 << b);

	/* algorithms */
	int i, j;
	for (i = 0; i < maxval; i++)
	{
		for (j = 0; j < maxval; j++)
			dist[i][j] = hdistance(i, j);
	}
	memset(answer, 0, sizeof(int)*NMAX);
	generate(1);

	/* print */

	/* exit */
	//fclose(in);
	//fclose(out);
	//exit(0);
}