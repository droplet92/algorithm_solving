/*
ID: lhs14381
LANG: C
TASK: concom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCOMPANY	100

static FILE *in, *out;
int cache[NCOMPANY][NCOMPANY];
int n;

void main()
{
	in = fopen("concom.in", "r");
	out = fopen("concom.out", "w");

	/* gets data */
	fscanf(in, "%d", &n);

	int i, j, p;
	for (int l = 0; l < n; l++)
	{
		fscanf(in, "%d %d %d", &i, &j, &p);
		cache[i - 1][j - 1] = p;
	}

	/* algorithm */
	int sentinel = 0;
	for (int l = 0; l < NCOMPANY; l++)
	{
		int stack[NCOMPANY] = { 0 };
		do
		{
			sentinel = 0;
			for (int m = 0; m < NCOMPANY; m++)
			{
				if (stack[m]) continue;
				if (cache[l][m] > 50)
				{
					for (int a = 0; a < NCOMPANY; a++)
					{
						if (cache[l][a] < 100)
							cache[l][a] += cache[m][a];
					}

					stack[m] = 1;
					sentinel = 1;
				}
			}
		} while (sentinel);
	}

	/* prints */
	for (int l = 0; l < NCOMPANY; l++)
	{
		for (int m = 0; m < NCOMPANY; m++)
		{
			if (l == m) continue;
			if (cache[l][m] > 50)
				fprintf(out, "%d %d\n", l + 1, m + 1);
		}
	}

	/* exit */
	exit(0);
}