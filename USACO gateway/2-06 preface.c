/*
ID: lhs14381
LANG: C
TASK: preface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN	3500
#define NLETTER	7

/*
RULE:	I II III IV V VI VII VIII IX X
LETTER: I V X L C D M
*/

FILE *in, *out;

char letter[] = { 'I','V','X','L','C','D','M' };
int mul[] = { 0,1,10,100,1000 };

int table[MAXN][NLETTER];
int n;

void main()
{
	in = fopen("preface.in", "r");
	out = fopen("preface.out", "w");

	/* get inputs */
	fscanf(in, "%d", &n);

	/* algorithms */
	int i, j, divider, divr;
	int foo, bar, baz;

	for (i = 1, divider = 1; i <= n; i++)
	{
		if (i == mul[divider + 1])
			++divider;

		memcpy(table[i], table[i - 1], sizeof(int)*NLETTER);

		for (j = i, divr = divider; j > 0; j %= mul[divr])
		{
			while (j < mul[divr])
				--divr;

			foo = (j / mul[divr]) / 5;
			bar = (j / mul[divr]) % 5;
			baz = (divr - 1) * 2;

			if (bar == 4)
			{
				table[i][0 + baz] += 1;			// 10^(n-1)
				table[i][1 + foo + baz] += 1;	// 5^n or 10^n
			}
			else if (bar == 0)
				table[i][foo + baz] += 1;		// 5^n or 10^n
			else
			{
				table[i][foo + baz] += foo;		// 5^n
				table[i][baz] += bar;			// 10^n
			}
		}
	}

	/* print */
	for (i = 0; (i < NLETTER && table[n][i]); i++)
		fprintf(out, "%c %d\n", letter[i], table[n][i]);

	/* exit */
	fclose(in);
	fclose(out);
	exit(0);
}