#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN	5

long long pow(int a, int b) {
	long long temp = 1;		/* ��ȯ�� */
	int i;					/* ī���� */

	for (i = 0; i < b; ++i) temp *= a;
	return temp;
}

//false�� 0��, true�� ������ ���� ��ȯ
int getOnes(int n) {
	long long ones;			/* 10^i�� �ڸ� ���� */
	int i;					/* ī���� */

	ones = 1;
	i = 0;

	do {
		ones += pow(10, ++i);
	} while (ones % n);

	return i + 1;
}

int main() {
	FILE * fs;				/* ���� ��Ʈ�� */
	char text[MAXLEN + 1];	/* �Է¹��� ���ڿ� */
	int n;					/* ����� ���� */
	int len;				/* ������ �ڸ��� */

	fs = fopen("#36 Ones.txt", "rt");

	while (fgets(text, MAXLEN + 1, fs)) {
		if (text[strlen(text) - 1] == '\n')
			text[strlen(text) - 1] = 0;
		n = atoi(text);

		printf("%d\n", getOnes(n));
	}
	fclose(fs);
	return 0;
}

/*
3
7
9901
*/