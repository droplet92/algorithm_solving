#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN		10
#define MAXINT_BIT	32

int numLen(int n) {
	int len = 0;	/* n의 자릿수 */

	while (n / (int)(exp(log(10)*len++)));
	return len - 1;
}

void getPow(int n) {
	int pow2;		/* 2^n */
	int head;		/* 2^n의 첫째 자리 숫자 */
	int len = 0;	/* 2^n의 자릿수 */
	int nlen = 0;	/* n의 자릿수 */
	int e = 7;		/* 지수, 카운터 */

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
	char s[MAXLEN];		/* 입력받은 문자열 */

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