#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN		9		/* ���� 3 + space + ���� 3 + enter + null */

int FindDepth(int n, int d) {
	if ((d == 0) || (d > n / 2)) return 0;			/* �ּ� ���� 1, �ִ� ���� (n/2) */
	if ((d == 1) || (d == n / 2)) return 1;			/* ���̰� 1�� ǥ������ 1�� */
	return FindDepth(n - 2, d - 1) + FindDepth(n - 2, d) * 2;
}

int main() {
	int n;				/* ���� */
	int d;				/* ���� */
	int result;			/* ����� */
	char text[MAXLEN];	/* �ӽ� ���ڿ� */
	int i, j;			/* ī���� */

	while (fgets(text, MAXLEN, stdin)) {
		//n�� d �Է�
		text[strlen(text) - 1] = 0;
		if (!strlen(text)) continue;

		n = atoi(strtok(text, " "));
		d = atoi(strtok(NULL, " "));

		//���
		if (n % 2) result = 0;
		else result = FindDepth(n, d);

		//���� �ʿ�
		j = 0;
		if ((2 <= d) && (d <= n / 2 - 2)) {
			for (i = 3; i < (n / 2 - j); ++i, ++j)
				result -= (n / 2 - 3);
		}

		//��� ���
		printf("%d\n", result);
	}
	return 0;
}