#include <stdio.h>

/* 모든 부분집합 구하기 */

#define MAX_CANDIDATES	100
#define NMAX			50
typedef enum { False, True } Bool;

void backtrack(int[], int, int);
Bool is_a_solution(int[], int, int);
void process_solution(int[], int, int);
void construct_candidates(int[], int, int, int[], int*);
void generate_subsets(int);

Bool finished = False;

void backtrack(int a[], int k, int n)
{
	int c[MAX_CANDIDATES];		/* 다음 위치가 될 수 있는 후보 위치 */
	int ncandidates;			/* 다음 위치가 될 수 있는 후보 개수 */
	int i;						/* 카운터 */

	if (is_a_solution(a, k, n))
		process_solution(a, k, n);
	else
	{
		++k;
		construct_candidates(a, k, n, c, &ncandidates);
		for (i = 0; i < ncandidates; ++i)
		{
			a[k] = c[i];
			backtrack(a, k, n);
			if (finished) return;
		}
	}
}

Bool is_a_solution(int a[], int k, int n)
{
	if (k == n) return True;
	return False;
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	c[0] = True;
	c[1] = False;
	*ncandidates = 2;
}

void process_solution(int a[], int k, int n)
{
	int i;

	printf("{");
	for (i = 1; i <= k; ++i)
		if (a[i] == True) printf(" %d", i);
	printf(" }\n");
}

void generate_subsets(int n)
{
	int a[NMAX];
	backtrack(a, 0, n);
}

int main()
{
	generate_subsets(3);
	return 0;
}