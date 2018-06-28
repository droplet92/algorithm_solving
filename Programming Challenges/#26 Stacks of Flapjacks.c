#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPANCAKE	30
#define TEXTLEN		70

void swap(int *lhs, int *rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

typedef struct {
	int data[NPANCAKE];
	int last;
} stack;

void init_stack(stack *s) {
	s->data[0] = 0;
	s->last = 0;
}

void push_back(int x, stack *s) {
	s->data[++(s->last)] = x;
}

void clear(stack *s) {
	int i;

	for (i = 0; i < (s->last); ++i) s->data[i] = 0;
	s->last = 0;
}

void show(stack s) {
	int i;
	for (i = 1; i <= (s.last); ++i)
		printf("%d ", s.data[i]);
	puts("\b");
}

void flip(int idx, stack *s) {
	int i;
	int diff;

	diff = (s->last) - idx;

	for (i = 0; i < (diff / 2) + (diff % 2); ++i)
		swap(&s->data[idx + i], &s->data[s->last - i]);
}

void insertion_sort(stack *s)
{
	int i, j;

	for (i = 1; i < (s->last); ++i)
	{
		j = i;
		while ((j > 0) && (s->data[j + 1] < s->data[j]))
		{
			flip(j, s);
			printf("%d ", j);
			--j;
		}
	}
}

int main()
{
	stack s;				/* ������ũ ���� */
	char * temp;			/* �ӽ� ���� */
	char text[TEXTLEN];		/* ������ �޾ƿ� ���ڿ� */
	init_stack(&s);

	while (fgets(text, TEXTLEN, stdin))
	{
		/* ���ÿ� �߰� */
		text[strlen(text) - 1] = 0;
		temp = strtok(text, " \n");
		push_back(atoi(temp), &s);

		while (temp = strtok(NULL, " \n"))
			push_back(atoi(temp), &s);

		/* �ݴ�� ����Ǿ� �����Ƿ� ��ü ������ */
		//flip(1, &s);

		/* ���� ���� �� �ø�Ƚ�� ��� */
		show(s);
		insertion_sort(&s);
		puts("0");

		clear(&s);
	}
	return 0;
}

/*
1 2 3 4 5
5 4 3 2 1
5 1 2 3 4
*/