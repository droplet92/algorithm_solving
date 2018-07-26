#include <stdio.h>
#define MAX 100
int CountMine(char(*)[MAX][MAX], int, int);
int m, n;

void InitBoard(char (*before)[MAX][MAX]) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%c", &(*before)[i][j]);
		}
		getchar();
	}
}

void Decryption(int (*after)[MAX][MAX], char (*before)[MAX][MAX]) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			(*after)[i][j] = CountMine(before, i, j);
		}
	}
}

int CountMine(char (*board)[MAX][MAX], int x, int y) {
	int count = 0;

	for (int i = x - 1; i <= x + 1; ++i) {
		if (i < 0 || i > m) continue;

		for (int j = y - 1; j <= y + 1; ++j) {
			if (j < 0 || j > n) continue;
			if (i == x && j == y) continue;

			if ((*board)[i][j] == '*')
				++count;
		}
	}
	return count;
}

void ShowBoard(int (*after)[MAX][MAX], char (*before)[MAX][MAX]) {
	int count = 0;

	do {
		printf("\nField #%d", ++count);
		puts("");

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((*before)[i][j] == '*')
					printf("*");
				else
					printf("%d", (*after)[i][j]);
			}
			puts("");
		}
	} while (!count);
}

int main() {
	int after[MAX][MAX] = { 0 };
	char before[MAX][MAX] = { 0 };

	scanf("%d %d", &m, &n);
	getchar();

	InitBoard(&before);
	Decryption(&after, &before);

	ShowBoard(&after, &before);

	return 0;
}