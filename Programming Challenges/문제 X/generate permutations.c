#include <stdio.h>

/* ��� ���� ���ϱ� */

#define MAX_CANDIDATES	10
#define NMAX			10
typedef enum { False, True } Bool;

void backtrack(int[], int, int);
Bool is_a_solution(int[], int, int);
void process_solution(int[], int, int);
void construct_candidates(int[], int, int, int[], int*);
void generate_permutations(int);

void backtrack(int a[], int k, int n)
{
	int c[MAX_CANDIDATES];		/* ���� ��ġ�� �� �� �ִ� �ĺ� ��ġ */
	int ncandidates;			/* ���� ��ġ�� �� �� �ִ� �ĺ� ���� */
	int i;						/* ī���� */

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
	int i;					/* ī���� */
	Bool in_perm[NMAX];		/* ������ ����ִ� ���� */

	for (i = 1; i < NMAX; ++i) in_perm[i] = False;
	for (i = 0; i < k; ++i) in_perm[a[i]] = True;

	*ncandidates = 0;
	for (i = 1; i <= n; ++i)
	{
		if (in_perm[i] == False)
			c[(*ncandidates)++] = i;
	}
}

void process_solution(int a[], int k, int n)
{
	int i;

	for (i = 1; i <= k; ++i) printf(" %d", a[i]);
	puts("");
}

void generate_permutations(int n)
{
	int a[NMAX] = { 0 };
	backtrack(a, 0, n);
}

void main() { generate_permutations(4); }