#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN		5
#define NUMBERS		9

int pow(int base, int exp) {
	int i, temp = 1;
	for (i = 0; i < exp; ++i) temp *= base;
	return temp;
}

int factorial(int n) {
	int i, temp = 1;
	for (i = n; i > 1; --i) temp *= i;
	return temp;
}

void InitArr(int arr[]) {
	int i;
	for (i = 0; i < NUMBERS; ++i) arr[i] = 0;
}

void OverTwos(int target[], int source[]) {
	int i;
	for (i = 1; i < NUMBERS; ++i)
		target[i] = source[i];
}

int Numbers(int arr[]) {
	int count = 0;
	int i;

	for (i = 0; i < NUMBERS; ++i) 
		count += arr[i];
	return count;
}

int Kinds(int arr[]) {
	int count = 0;
	int i;

	for (i = 0; i < NUMBERS; ++i) if (arr[i]) ++count;
	return count;
}

int getCase(int arr[]) {
	int kinds;		/* ���� */
	int numbers;	/* ���� ���� */
	int temp;		/* �ӽ� ���� */
	int i;			/* ī���� */

	kinds = Kinds(arr);
	numbers = Numbers(arr);
	temp = factorial(numbers);

	//temp�� �� ������ ���丮��� ����
	for (i = 0; i < NUMBERS; ++i) {
		if (arr[i]) temp /= factorial(arr[i]);
	}
	return temp;
}

void func(int arr[], int *sum) {
	int n[NUMBERS];	/* �� �迭 */
	int ones;		/* 1�� ���� */
	int quot;		/* quotient, �� */
	int rem;		/* remainder, ������, ���� 1�� ���� */
	int div, j, k;	/* ī���� */

	InitArr(n);
	ones = arr[0];

	//(�ߺ����� �����ϴ� ����� ��)*2^n, (numbers-1)-(numbers-kinds)
	*sum += getCase(arr)*pow(2, ones);

	//�ٸ� ��� ã��, 1�� ������ ���� ����� �����Ƿ� 2����
	for (div = 2; div < NUMBERS; ++div) {
		if (div == 4) continue;		//4�� ���� ����
		if (arr[div - 1]) break;	//�ô� ���ڴ� �ٽ� ���� ����

		quot = ones / div;
		rem = ones % div;

		if (!quot) break;	//���� ������ ����
		for (j = 0; j < quot; ++j) {
			//2�̻� �߰�
			OverTwos(n, arr);

			//1 �߰�
			n[0] = rem + (div*j);

			//i �߰�
			n[div - 1] += (quot - j);

			func(n, sum);

			//n�� ��� �ʱ�ȭ
			InitArr(n);
		}
	}
}

int main() {
	int n;				/* ���� */
	char text[MAXLEN];	/* �ӽ� ���ڿ� */
	int sum;			/* ��� �� */
	int arr[NUMBERS];	/* ���� �迭 */
	int i;				/* ī���� */

	while (fgets(text, MAXLEN, stdin)) {
		InitArr(arr);
		sum = 0;
		text[strlen(text) - 1] = 0;

		//4�� 1�� ��ȯ
		for (i = 0; i < strlen(text); ++i)
			if (text[i] == '4') text[i] = '1';

		//���ڿ��� ������ ��ȯ
		n = atoi(text);

		//n�� ���� �� �ִ� ��� ���ϱ�
		arr[0] = n;
		func(arr, &sum);

		printf("%d\n", sum);
	}
	return 0;
}

/*
2
3
*/