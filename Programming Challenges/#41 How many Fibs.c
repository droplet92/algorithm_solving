#include <stdio.h>
#include <math.h>
#include "bignum.h"

//�Ǻ���ġ
void Fibonacci(int n, bign *b) {
	bign fib;		/* �Ǻ���ġ ���� */
	bign lhs, rhs;	/* ���� */
	int len;		/* �Ǻ���ġ ������ ���� */
	int i;			/* ī���� */

	init_num(&lhs);
	init_num(&rhs);
	rhs.digits[rhs.lastbit] = '1';	/* lhs�� 0, rhs�� 1 */

	for (i = 0; i < n; ++i) {
		init_num(&fib);

		add_num(&lhs, &rhs, &fib);
		copy_num(&lhs, &rhs);
		copy_num(&rhs, &fib);
	}
	copy_num(b, &fib);
}

int main() {
	bign a, b;			/* �Է¹��� ���� */
	bign begin, end;	/* �ӽ� ���� */
	int i, j;			/* ī���� */

	init_num(&a);
	init_num(&b);
	get_num(&a);
	get_num(&b);

	while (!(a.digits[a.lastbit] == '0' && a.lastbit == 0)
		&& !(b.digits[b.lastbit] == '0' && b.lastbit == 0))
	{
		i = 0;

		//������ ã��
		do {
			init_num(&begin);
			Fibonacci(++i, &begin);
		} while (isLeftSameOrGreater(&a, &begin));

		j = i;
		//���� ã��
		do {
			init_num(&end);
			Fibonacci(++j, &end);
		} while (isLeftSameOrGreater(&b, &end));

		//��� ���
		printf("%d\n", j - i);

		//������ �Է�
		init_num(&a);
		init_num(&b);
		get_num(&a);
		get_num(&b);
	}
	
	return 0;
}

/*
10 100
1234567890 9876543210
0 0
*/