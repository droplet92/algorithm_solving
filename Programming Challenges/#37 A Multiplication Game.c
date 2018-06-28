#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN	11

double logB(int base, int x) {
	return log(x) / log(base);
}

int toDiv(int target, int turn) {
	int temp;	/* ������ �� �� ���� �� �ִ��� */
	int i;		/* ī���� */

	//�����
	if (turn % 2) {
		//1�� ������ ���� ����
		for (i = 9; i >= 2; --i) {
			temp = ceil(logB(i, target));
			if (temp == 1) return i;
		}
		//Ȧ���� ����
		for (i = 2; i <= 9; ++i) {
			temp = ceil(logB(i, target));
			if (temp % 2) break;
		}
	}
	//������
	else {
		//1�� ������ ���� ����
		for (i = 2; i <= 9; ++i) {
			temp = ceil(logB(i, target));
			if (temp == 1) return i;
		}
		//Ȧ���� ����
		for (i = 9; i >= 2; --i) {
			temp = ceil(logB(i, target));
			if (temp % 2) break;
		}
	}
	return i;
}

void StartGame(unsigned int n) {
	const char * name[2] = { "Stan", "Ollie" };
	int turn = 0;	/* ���� ����, 0�� Stan, 1�� Ollie */
	int divider;	/* ������ ���� */
	int atk = 0;	/* ���������� �÷����ϴ��� ���� */

	if (!((int)ceil(logB(9, n)) % 2)) {
		++turn;
		atk = 1;
	}
	do {
		divider = toDiv(n, turn);
		n /= divider;
		printf("%d ", n);

		++turn;
	} while ((n != 0) && (n != 1));
	puts("");
	printf("%s wins.\n", name[(turn + 1 + atk) % 2]);
}

int main() {
	unsigned int n;		/* ���� ���� n */
	char text[MAXLEN];	/* �ӽ� ���ڿ� */

	while (fgets(text, MAXLEN, stdin)) {
		text[strlen(text) - 1] = 0;
		n = atoi(text);
		
		/*
		for (int i = 2; i <= 9; ++i)
			printf("%d ", (int)ceil(logB(i, n)));
		puts("");
		*/
		StartGame(n);
	}
	return 0;
}

/*
162
17
34012226
*/