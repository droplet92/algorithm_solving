#include <stdio.h>
#include <stdlib.h>

/* 8���� �� */

#define NMAX	50
typedef enum { False, True } Bool;

void backtrack(int[], int, int);
Bool is_a_solution(int, int);
void process_solution();
void construct_candidates(int[], int, int, int[], int*);
void generate_permutations(int);

int solution_count;

void backtrack(int a[], int k, int n)
{
	int c[NMAX];		/* ���� ��ġ�� �� �� �ִ� �ĺ� ��ġ */
	int ncandidates;	/* ���� ��ġ�� �� �� �ִ� �ĺ� ���� */
	int i;				/* ī���� */

	if (is_a_solution(k, n))
		process_solution();
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

Bool is_a_solution(int k, int n)
{
	if (k == n) return True;
	return False;
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i, j;			/* ī���� */
	Bool legal_move;	/* �̵� ���� ���� */

	*ncandidates = 0;
	for (i = 1; i <= n; ++i)
	{
		legal_move = True;
		for (j = 1; j < k; j++)
		{
			/* break�� ����� �ӵ� �ξ� ������ */
			if (abs(k - j) == abs(i - a[j])) {
				legal_move = False;
				break;
			}
			if (i == a[j]){
				legal_move = False;
				break;
			}
		}
		if (legal_move == True)
		{
			c[*ncandidates] = i;
			*ncandidates += 1;
		}
	}
}

void process_solution()
{
	solution_count++;
}

void generate_permutations(int n)
{
	int a[NMAX];
	solution_count = 0;
	backtrack(a, 0, n);
	printf("n=%d	solution_count=%d\n", n, solution_count);
}

void main()
{
	int i;
	for (i = 1; i <= 20; ++i)
		generate_permutations(i); 
}