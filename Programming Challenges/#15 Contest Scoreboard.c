#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//정답 하나라도 있으면 정답
//시간 벌점: 첫 정답이 제출될 때까지 걸린 시간
//           + 정답 전의 오답 당 20

//입력: 팀 번호, 문제 번호, 
//출력: 팀 번호, 푼 문제 수, 시간 벌점
//출력 순서: 푼 문제 많은 수->패널티 적은 순

typedef struct {
	int teamNum;
	int solved;
	int delay;
} score;

void swap(score * lhs, score * rhs) {
	score temp;
	temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void bubble_sort(score(*teams)[100]) {
	for (int i = 100; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if ((*teams)[j].solved < (*teams)[j + 1].solved)
				swap(&(*teams)[j], &(*teams)[j + 1]);
		}
	}
	for (int i = 100; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if ((*teams)[j].solved == (*teams)[j + 1].solved &&
				(*teams)[j].delay < (*teams)[j + 1].delay)
				swap(&(*teams)[j], &(*teams)[j + 1]);
		}
	}
}

void init(score(*teams)[100]) {
	for (int i = 0; i < 100; ++i) {
		(*teams)[i].teamNum = i + 1;
		(*teams)[i].solved = 0;
		(*teams)[i].delay = 0;
	}
}

int main() {
	int n, i;
	char line[10];
	score teams[100];
	char l;
	int team, time;

	init(&teams);

	scanf("%d", &n);
	//n회 반복
	for (int r = 0; r < n; ++r) {
		while(getchar() != '\n');
		getchar();	//엔터 입력

		while (fgets(line, 10, stdin)) {
			if (line[0] == '\n') break;
			for (int i = 0; i < 10; ++i) {
				if (line[i] == '\n')
					line[i] = 0;
			}

			//문자열 자르기
			team = atoi(strtok(line, " "));
			strtok(NULL, " ");
			time = atoi(strtok(NULL, " "));
			l = *strtok(NULL, " ");

			//성공한 경우, 벌점 +걸린 시간 & 푼 문제 +1
			if (l == 'C') {
				++teams[team - 1].solved;
				teams[team - 1].delay += time;
			}
			//실패한 경우, 벌점 +20
			else if (l == 'I') {
				teams[team - 1].delay += 20;
			}
		}

		//결과 산정
		bubble_sort(&teams);

		//결과 발표
		i = 0;
		while (teams[i].solved || teams[i].delay) {
			printf("%d %d %d\n", teams[i].teamNum,
				teams[i].solved, teams[i].delay);
			++i;
		}
	}
	return 0;
}

/*
1

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C

*/