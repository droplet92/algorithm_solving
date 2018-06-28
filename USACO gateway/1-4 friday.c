/*
ID: lhs14381
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>

#define START_YEAR		1900
#define FEB				1
#define MON				2
#define THIRTEEN		13
#define NWEEK			7
#define NYEAR			12
#define LEAF_YEAR(year)	(!((year)%4) && (((year)%100) || !((year)%2000)) ? 29 : 28)

void process(size_t n, int ntimes[])
{
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, j;
	int start = MON;

	for (i = START_YEAR; i < (START_YEAR + n); i++)
	{
		days[FEB] = LEAF_YEAR(i);

		for (j = 0; j < NYEAR; j++) {
			++ntimes[(THIRTEEN + start - 1) % NWEEK];
			start = (start + days[j]) % NWEEK;
		}
	}
}

void main()
{
	FILE * in = fopen("friday.in", "r");
	FILE * out = fopen("friday.out", "w");

	size_t n;
	size_t ntimes[NWEEK] = { 0 };

	fscanf(in, "%zu", &n);
	fclose(in);

	process(n, ntimes);
	for (int i = 0; i < (NWEEK - 1); i++) {
		fprintf(out, "%zu ", ntimes[i]);
	}
	fprintf(out, "%zu\n", ntimes[NWEEK - 1]);
	fclose(out);
	exit(0);
}