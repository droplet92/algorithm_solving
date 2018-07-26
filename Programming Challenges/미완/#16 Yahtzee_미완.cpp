#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�켱���� ť ���?

#define MAXLEN 11	/* �ִ� ���ڿ� ���� */
#define ROUND 13	/* ���� ���� */
#define DICE_PIP 6	/* �ֻ��� ���� ���� */
#define DICE_NUM 5	/* ������ �ֻ��� ���� */

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

	//ù �� �Է�
	token = strtok(firstline, " ");
	++round[0][atoi(token) - 1];

	while (token = strtok(NULL, " ")) {
		++round[0][atoi(token) - 1];
	}

	//������ �� �Է�
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &num);
			++round[i + 1][num - 1];
		}
	}

	//�Է¹��� ����
	while (getchar() != '\n');
}

int main() {
	int round[ROUND][DICE_PIP];
	char firstline[MAXLEN];

	//�� ���� �Է� ��, ���α׷� ����
	while (fgets(firstline, MAXLEN, stdin) != NULL) {
		firstline[strlen(firstline) - 1] = 0;

		//round �ʱ�ȭ �� �Է�
		InitRound(round);
		SetRound(round, firstline);

		//���ھ� ���
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