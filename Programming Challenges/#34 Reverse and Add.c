#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN	10		/* 숫자의 최대 자릿수 */
typedef enum { False, True } Bool;

int pow(int a, int b) {
	int i, temp = 1;
	for (i = 0; i < b; ++i) temp *= a;
	return temp;
}

void reverse(char *n, char *rev) {
	int len = strlen(n);	/* n의 자릿수 */
	int i;						/* 카운터 */

	for (i = 0; i < len; ++i)
		rev[i] = n[len - i - 1];
}

Bool isPalindrome(char *n) {
	int len = strlen(n);	/* n의 자릿수 */
	int i;						/* 카운터 */

	for (i = 0; i < (len / 2 + len % 2); ++i)
		if (n[i] != n[len - i - 1]) return False;

	return True;
}

int main() {
	int n;				/* 테스트 케이스 */
	char num[MAXLEN];	/* 회문을 찾을 숫자 */
	char rev[MAXLEN];	/* 뒤집어진 수 */
	int count = 0;		/* 반복 횟수 */
	int i, j;				/* 카운터 */

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; ++i) {
		count = 0;
		for (j = 0; j < MAXLEN; ++j) rev[j] = 0;

		fgets(num, MAXLEN + 1, stdin);
		num[strlen(num) - 1] = 0;

		do {
			reverse(num, rev);
			//printf와 같은 방식으로 버퍼에 쓰는 함수, stdio.h에 포함
			sprintf(num, "%d", atoi(num) + atoi(rev));
			++count;
		} while (!isPalindrome(num));
		printf("%d %s\n", count, num);
	}
	return 0;
}

/*
3
195
265
750
*/