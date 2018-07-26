#include <stdio.h>
#include <stdlib.h>

/* 8개의 퀸 */

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
	int c[NMAX];		/* 다음 위치가 될 수 있는 후보 위치 */
	int ncandidates;	/* 다음 위치가 될 수 있는 후보 개수 */
	int i;				/* 카운터 */

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
	int i, j;			/* 카운터 */
	Bool legal_move;	/* 이동 가능 여부 */

	*ncandidates = 0;
	for (i = 1; i <= n; ++i)
	{
		legal_move = True;
		for (j = 1; j < k; j++)
		{
			/* break를 지우면 속도 훨씬 느려짐 */
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