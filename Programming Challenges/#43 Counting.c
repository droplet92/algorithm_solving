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
	int kinds;		/* 종류 */
	int numbers;	/* 숫자 개수 */
	int temp;		/* 임시 숫자 */
	int i;			/* 카운터 */

	kinds = Kinds(arr);
	numbers = Numbers(arr);
	temp = factorial(numbers);

	//temp를 각 숫자의 팩토리얼로 나눔
	for (i = 0; i < NUMBERS; ++i) {
		if (arr[i]) temp /= factorial(arr[i]);
	}
	return temp;
}

void func(int arr[], int *sum) {
	int n[NUMBERS];	/* 빈 배열 */
	int ones;		/* 1의 개수 */
	int quot;		/* quotient, 몫 */
	int rem;		/* remainder, 나머지, 전부 1로 간주 */
	int div, j, k;	/* 카운터 */

	InitArr(n);
	ones = arr[0];

	//(중복없이 나열하는 경우의 수)*2^n, (numbers-1)-(numbers-kinds)
	*sum += getCase(arr)*pow(2, ones);

	//다른 경우 찾기, 1로 나누면 같은 결과가 나오므로 2부터
	for (div = 2; div < NUMBERS; ++div) {
		if (div == 4) continue;		//4는 세지 않음
		if (arr[div - 1]) break;	//셌던 숫자는 다시 세지 않음

		quot = ones / div;
		rem = ones % div;

		if (!quot) break;	//몫이 없으면 종료
		for (j = 0; j < quot; ++j) {
			//2이상 추가
			OverTwos(n, arr);

			//1 추가
			n[0] = rem + (div*j);

			//i 추가
			n[div - 1] += (quot - j);

			func(n, sum);

			//n을 모두 초기화
			InitArr(n);
		}
	}
}

int main() {
	int n;				/* 정수 */
	char text[MAXLEN];	/* 임시 문자열 */
	int sum;			/* 결과 합 */
	int arr[NUMBERS];	/* 숫자 배열 */
	int i;				/* 카운터 */

	while (fgets(text, MAXLEN, stdin)) {
		InitArr(arr);
		sum = 0;
		text[strlen(text) - 1] = 0;

		//4는 1로 변환
		for (i = 0; i < strlen(text); ++i)
			if (text[i] == '4') text[i] = '1';

		//문자열을 정수로 변환
		n = atoi(text);

		//n을 만들 수 있는 경우 구하기
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