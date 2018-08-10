/*
ID: lhs14381
LANG: C
TASK: money
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VMAX	25
#define NMAX	10000

static FILE *in, *out;
int v, n;
long long coins[VMAX];
long long cache[VMAX][NMAX];

int compare(const void* lhs, const void* rhs)
{
	return *(int*)rhs - *(int*)lhs;
}

long long dfs(int stage, int sum)
{
	if (cache[stage][sum] != -1)
		return cache[stage][sum];

	if (stage == v) return 0;
	if (sum == 0) return 1;

	int coin = coins[stage];
	long long res = 0;

	if (stage == v - 1)
		return (sum % coin == 0);
	else
	{
		for (int i = sum / coin; i >= 0; i--)
			res += dfs(stage + 1, sum - i * coin);
		cache[stage][sum] = res;
		return res;
	}
}

void main()
{
	in = fopen("money.in", "r");
	out = fopen("money.out", "w");

	/* gets data */
	fscanf(in, "%d %d", &v, &n);
	for (int i = 0; i < v; i++)
		fscanf(in, "%d", &coins[i]);

	/* algorithm */
	memset(cache, -1, sizeof(cache));
	qsort(coins, v, sizeof(long long), compare);

	/* prints */
	fprintf(out, "%lld\n", dfs(0, n));

	/* exit */
	exit(0);
}