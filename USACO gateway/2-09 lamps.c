/*
ID: lhs14381
LANG: C
TASK: lamps
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBUTTON	4
#define NMAX	100

static FILE *in, *out;
static int n, c;
static int muston[NMAX + 1], mustoff[NMAX + 1];
static int dp[NBUTTON*2][NMAX];		// 0000~1111, 8~15 collides with 0~7

void swap(int lhs, int rhs)
{
	int* temp[NMAX];
	memcpy(temp, dp[lhs], sizeof(int)*n);
	memcpy(dp[lhs], dp[rhs], sizeof(int)*n);
	memcpy(dp[rhs], temp, sizeof(int)*n);
}

int compare(int lhs, int rhs)
{
	for (int i = 0; i < n; i++)
	{
		if (dp[lhs][i] > dp[rhs][i])
			return 1;

		else if (dp[lhs][i] < dp[rhs][i])
			return -1;
	}
	return 0;
}

void sort()
{
	int i, j, min;
	for (i = 0; i < NBUTTON * 2; i++)
	{
		min = i;

		for (j = (i + 1); j < NBUTTON * 2; j++)
		{
			if (compare(min, j) == 1)
				min = j;
		}
		if (i != min)
			swap(i, min);
	}
}

void initArray(int* arr)
{
	for (int i = 0;; i++)
	{
		fscanf(in, "%d", &arr[i]);
		if (arr[i] == -1) return;
	}
}

void press(int* arr, int begin, int gap)
{
	for (int i = begin; i < n; i += gap)
		arr[i] = (arr[i] + 1) % 2;
}

void pressbtn(int* arr, int btn)
{
	switch (btn)
	{
	case 0:	press(arr, 0, 1); break;
	case 1: press(arr, 0, 2); break;
	case 2: press(arr, 1, 2); break;
	case 3: press(arr, 0, 3); break;
	}
}

void main()
{
	in = fopen("lamps.in", "r");
	out = fopen("lamps.out", "w");

	/* gets data */
	fscanf(in, "%d %d", &n, &c);
	initArray(muston);
	initArray(mustoff);

	/* algorithm */
	int cnt, btn, lamp;
	int i, j;

	for (btn = 0; btn < NBUTTON*2; btn++)
	{
		for (lamp = 0; lamp < n; lamp++)
			dp[btn][lamp] = 1;

		for (i = 0, j = 0x08; i < NBUTTON; i++, j >>= 1)
		{
			if ((btn & j) == j)
				pressbtn(dp[btn], i);
		}
	}
	sort();

	/* prints */
	if (c == 0)
	{
		if (mustoff[0] != -1)
			fprintf(out, "IMPOSSIBLE\n");
		else
		{
			for (lamp = 0; lamp < n; lamp++)
				fprintf(out, "1");
			fprintf(out, "\n");
		}
	}
	else
	{
		cnt = 0;
		for (btn = 0; btn < NBUTTON*2; btn++)
		{
			for (lamp = 0; muston[lamp] != -1; lamp++)
			{
				if (dp[btn][muston[lamp] - 1] == 0)
					goto NEXT;
			}
			for (lamp = 0; mustoff[lamp] != -1; lamp++)
			{
				if (dp[btn][mustoff[lamp] - 1] == 1)
					goto NEXT;
			}
			for (lamp = 0; lamp < n; lamp++)
				fprintf(out, "%d", dp[btn][lamp]);
			fprintf(out, "\n");

			++cnt;
		NEXT:
			;
		}
		if (cnt == 0)
			fprintf(out, "IMPOSSIBLE\n");
	}

	/* exit */
	exit(0);
}
