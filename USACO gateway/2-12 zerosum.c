/*
ID: lhs14381
LANG: C
TASK: zerosum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOPER	3
#define NDIGIT	9

static FILE *in, *out;
char oper[NOPER] = { ' ', '+', '-' };
int n;

int issolution(int arr[])
{
	int sum = 0, next = 1;
	char op = '+';

	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == ' ')
		{
			next *= 10;
			next += (i + 1);
		}
		else
		{
			if (op == '+')
				sum += next;
			else
				sum -= next;

			next = (i + 1);
			op = arr[i - 1];
		}
	}
	if (op == '+')
		sum += next;
	else
		sum -= next;
	return (sum == 0);
}

void dfs(int stage, int arr[])
{
	if (stage == (n - 1))
	{
		if (issolution(arr))
		{
			for (int i = 0; i < stage; i++)
				fprintf(out, "%d%c", i + 1, arr[i]);
			fprintf(out, "%d\n", n);
		}
	}
	else
	{
		for (int j = 0; j < NOPER; j++)
		{
			arr[stage] = oper[j];
			dfs(stage + 1, arr);
		}
	}
}

void main()
{
	in = fopen("zerosum.in", "r");
	out = fopen("zerosum.out", "w");

	/* gets data */
	fscanf(in, "%d", &n);

	/* algorithm */
	int empty[NDIGIT - 1];
	dfs(0, empty);

	/* prints */

	/* exit */
	exit(0);
}