#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//우선순위 큐 사용?

#define MAXLEN 11	/* 최대 문자열 길이 */
#define ROUND 13	/* 게임 라운드 */
#define DICE_PIP 6	/* 주사위 눈의 종류 */
#define DICE_NUM 5	/* 던지는 주사위 개수 */

typedef struct {
	int cards[DICE_PIP];
	int count;
} hand;

void init_hand(hand h[]) {
	for (int i = 0; i < ROUND; ++i) {
		for (int j = 0; j < DICE_PIP; ++j)
			h[i].cards[j] = 0;
		h[i].count = 0;
	}
}

void get_type(hand h[], int round[ROUND][DICE_PIP]) {
	for (int i = 0; i < ROUND; ++i) {
		for (int j = 0; j < DICE_NUM; ++j) {
			if (!h[i].cards[round[i][j]]) ++h[i].count;
			++h[i].cards[round[i][j]];
		}
	}
}

void FullHouse(int round[][DICE_PIP], int sum) {

}

void Straight(int round[][DICE_PIP], int sum) {

}

void AllSame(int round[][DICE_PIP], int sum) {

}

void OverlapAndChance(int round[][DICE_PIP], int sum) {

}

void SumOf(int num, int round[][DICE_PIP], int sum) {

}

void ShowScore(int round[][DICE_PIP]) {
	int bonus = 0, sum = 0;
	int score[ROUND] = { 0 };
	hand h[ROUND];

	init_hand(h);
	get_type(h, round);
}

void InitRound(int round[][DICE_PIP]) {
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 6; ++j)
			round[i][j] = 0;
	}
}

void SetRound(int round[][DICE_PIP], char firstline[]) {
	int num;
	char * token = (char*)malloc(MAXLEN * sizeof(char*));

	//첫 줄 입력
	token = strtok(firstline, " ");
	++round[0][atoi(token) - 1];

	while (token = strtok(NULL, " ")) {
		++round[0][atoi(token) - 1];
	}

	//나머지 줄 입력
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &num);
			++round[i + 1][num - 1];
		}
	}

	//입력버퍼 비우기
	while (getchar() != '\n');
}

int main() {
	int round[ROUND][DICE_PIP];
	char firstline[MAXLEN];

	//널 문자 입력 시, 프로그램 종료
	while (fgets(firstline, MAXLEN, stdin) != NULL) {
		firstline[strlen(firstline) - 1] = 0;

		//round 초기화 및 입력
		InitRound(round);
		SetRound(round, firstline);

		//스코어 계산
		get_type(round);
		ShowScore(round);
	}
	return 0;
}

/*
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 1 1 1 1
6 6 6 6 6
6 6 6 1 1
1 1 1 2 2
1 1 1 2 3
1 2 3 4 5
1 2 3 4 6
6 1 2 6 6
1 4 5 5 5
5 5 5 5 6
4 4 4 5 6
3 1 3 6 3
2 2 2 4 6
*/