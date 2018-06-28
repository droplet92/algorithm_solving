#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN	10		/* ������ �ִ� �ڸ��� */
typedef enum { False, True } Bool;

int pow(int a, int b) {
	int i, temp = 1;
	for (i = 0; i < b; ++i) temp *= a;
	return temp;
}

void reverse(char *n, char *rev) {
	int len = strlen(n);	/* n�� �ڸ��� */
	int i;						/* ī���� */

	for (i = 0; i < len; ++i)
		rev[i] = n[len - i - 1];
}

Bool isPalindrome(char *n) {
	int len = strlen(n);	/* n�� �ڸ��� */
	int i;						/* ī���� */

	for (i = 0; i < (len / 2 + len % 2); ++i)
		if (n[i] != n[len - i - 1]) return False;

	return True;
}

int main() {
	int n;				/* �׽�Ʈ ���̽� */
	char num[MAXLEN];	/* ȸ���� ã�� ���� */
	char rev[MAXLEN];	/* �������� �� */
	int count = 0;		/* �ݺ� Ƚ�� */
	int i, j;				/* ī���� */

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; ++i) {
		count = 0;
		for (j = 0; j < MAXLEN; ++j) rev[j] = 0;

		fgets(num, MAXLEN + 1, stdin);
		num[strlen(num) - 1] = 0;

		do {
			reverse(num, rev);
			//printf�� ���� ������� ���ۿ� ���� �Լ�, stdio.h�� ����
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