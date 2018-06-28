#include <stdio.h>

int pow(int a, int b) {
	int i, temp = 1;
	for (i = 0; i < b; ++i) temp *= a;
	return temp;
}

int main() {
	int a, b;			/* �Է¹��� ���� */
	int sum;			/* ���� �� */
	int lhs, rhs, s;	/* �ӽ� ���� */
	int carry;			/* �ø� Ƚ�� */
	int i;				/* ī���� */

	scanf("%d %d", &a, &b);
	while (a && b) {
		carry = 0;
		i = 0;
		sum = a + b;

		do {
			s = (sum % pow(10, i + 1)) / pow(10, i);
			lhs = (a % pow(10, i + 1)) / pow(10, i);
			rhs = (b % pow(10, i + 1)) / pow(10, i);

			if ((lhs + rhs != s) && (lhs + rhs + (carry != 0) != s)) {
				carry += 1;
			}
			++i;
		} while (lhs && rhs);

		if (carry == 0)
			printf("No carry operation.\n");
		else if (carry == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operation.\n", carry);

		scanf("%d %d", &a, &b);
	}
	return 0;
}

/*
123 456
555 555
123 594
0 0
*/