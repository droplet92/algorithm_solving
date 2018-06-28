#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN	5

long long pow(int a, int b) {
	long long temp = 1;		/* 반환값 */
	int i;					/* 카운터 */

	for (i = 0; i < b; ++i) temp *= a;
	return temp;
}

//false면 0을, true면 숫자의 길이 반환
int getOnes(int n) {
	long long ones;			/* 10^i의 자리 숫자 */
	int i;					/* 카운터 */

	ones = 1;
	i = 0;

	do {
		ones += pow(10, ++i);
	} while (ones % n);

	return i + 1;
}

int main() {
	FILE * fs;				/* 파일 스트림 */
	char text[MAXLEN + 1];	/* 입력받을 문자열 */
	int n;					/* 계산할 정수 */
	int len;				/* 숫자의 자릿수 */

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