#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN		10
#define MAXINT_BIT	32

int numLen(int n) {
	int len = 0;	/* n�� �ڸ��� */

	while (n / (int)(exp(log(10)*len++)));
	return len - 1;
}

void getPow(int n) {
	int pow2;		/* 2^n */
	int head;		/* 2^n�� ù° �ڸ� ���� */
	int len = 0;	/* 2^n�� �ڸ��� */
	int nlen = 0;	/* n�� �ڸ��� */
	int e = 7;		/* ����, ī���� */

	do {
		pow2 = exp(log(2)*e);
		nlen = numLen(n);
		len = numLen(pow2);

		head = pow2 / exp(log(10)*(len - nlen));
		
		if (++e == MAXINT_BIT) {
			puts("No power of 2");
			return;
		}
	} while ((head != n) || !(len > nlen * 2));
	printf("%d\n", --e);
}

int main() {
	char s[MAXLEN];		/* �Է¹��� ���ڿ� */

	while (fgets(s, MAXLEN + 1, stdin)) {
		s[strlen(s) - 1] = 0;
		getPow(atoi(s));
	}
	return 0;
}

/*
1
2
10
*/