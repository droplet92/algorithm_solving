#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� �ϳ��� ������ ����
//�ð� ����: ù ������ ����� ������ �ɸ� �ð�
//           + ���� ���� ���� �� 20

//�Է�: �� ��ȣ, ���� ��ȣ, 
//���: �� ��ȣ, Ǭ ���� ��, �ð� ����
//��� ����: Ǭ ���� ���� ��->�г�Ƽ ���� ��

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
	//nȸ �ݺ�
	for (int r = 0; r < n; ++r) {
		while(getchar() != '\n');
		getchar();	//���� �Է�

		while (fgets(line, 10, stdin)) {
			if (line[0] == '\n') break;
			for (int i = 0; i < 10; ++i) {
				if (line[i] == '\n')
					line[i] = 0;
			}

			//���ڿ� �ڸ���
			team = atoi(strtok(line, " "));
			strtok(NULL, " ");
			time = atoi(strtok(NULL, " "));
			l = *strtok(NULL, " ");

			//������ ���, ���� +�ɸ� �ð� & Ǭ ���� +1
			if (l == 'C') {
				++teams[team - 1].solved;
				teams[team - 1].delay += time;
			}
			//������ ���, ���� +20
			else if (l == 'I') {
				teams[team - 1].delay += 20;
			}
		}

		//��� ����
		bubble_sort(&teams);

		//��� ��ǥ
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