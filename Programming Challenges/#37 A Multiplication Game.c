#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN	11

double logB(int base, int x) {
	return log(x) / log(base);
}

int toDiv(int target, int turn) {
	int temp;	/* 앞으로 몇 번 나눌 수 있는지 */
	int i;		/* 카운터 */

	//방어적
	if (turn % 2) {
		//1이 있으면 게임 종료
		for (i = 9; i >= 2; --i) {
			temp = ceil(logB(i, target));
			if (temp == 1) return i;
		}
		//홀수를 선택
		for (i = 2; i <= 9; ++i) {
			temp = ceil(logB(i, target));
			if (temp % 2) break;
		}
	}
	//공격적
	else {
		//1이 있으면 게임 종료
		for (i = 2; i <= 9; ++i) {
			temp = ceil(logB(i, target));
			if (temp == 1) return i;
		}
		//홀수를 선택
		for (i = 9; i >= 2; --i) {
			temp = ceil(logB(i, target));
			if (temp % 2) break;
		}
	}
	return i;
}

void StartGame(unsigned int n) {
	const char * name[2] = { "Stan", "Ollie" };
	int turn = 0;	/* 게임 차례, 0은 Stan, 1은 Ollie */
	int divider;	/* 나누는 숫자 */
	int atk = 0;	/* 공격적으로 플레이하는지 여부 */

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
	unsigned int n;		/* 작은 정수 n */
	char text[MAXLEN];	/* 임시 문자열 */

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