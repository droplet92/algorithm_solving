/*
ID: lhs14381
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 14

int findIndex(char* names[], char* giver)
{
	int i = 0;
	while (names[i]) {
		if (!strcmp(names[i], giver)) {
			return i;
		}
		++i;
	}
	return -1;
}

void giveMoney(FILE* in, int from, int allowance, int to, char(*names)[], int* money)
{
	int i;
	int reciever;
	char name[NAMELEN];

	if (allowance <= 0) return;

	int div = allowance / to;
	int exchange = allowance % to;

	money[from] -= (allowance - exchange);

	for (i = 0; i < to; i++) {
		fscanf(in, "%s\n", name);
		reciever = findIndex(names, name);
		money[reciever] += div;
	}
}

void main()
{
	FILE * in = fopen("gift1.in", "r");
	FILE * out = fopen("gift1.out", "w");

	int np;
	char** names;
	int* money;

	char giver[NAMELEN];
	int allowance;
	int nrecieve;
	int i;

	/* get # of members */
	fscanf(in, "%d\n", &np);

	/* initialize */
	names = (char**)malloc(sizeof(char*)*np);
	money = (int*)malloc(sizeof(int)*np);
	memset(money, 0, sizeof(int)*np);

	/* get names of members */
	for (i = 0; i < np; i++) {
		names[i] = (char*)malloc(sizeof(char)*NAMELEN);
		fscanf(in, "%s\n", names[i]);
	}

	/* execute */
	for (i = 0; i<np; i++)
	{
		fscanf(in, "%s\n%d %d\n", giver, &allowance, &nrecieve);
		giveMoney(in, findIndex(names, giver), allowance, nrecieve, names, money);
	}
	fclose(in);

	/* print */
	for (i = 0; i < np; i++)
		fprintf(out, "%s %d\n", names[i], money[i]);

	fclose(out);
	exit(0);
}