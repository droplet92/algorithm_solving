#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 50
#define MAXKEY 20

void tolower(char * text) {
	int len = strlen(text);

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < 'Z' - 'A'; ++j)
			if (text[i] == 'A' + j) text[i] = 'a' + j;
	}
}

int isRightVector(char * text[MAXLEN], char * keys[MAXKEY], 
	int x, int y, int dx, int dy, int loop, int m, int n)
{
	int vector_x = dx - x;
	int vector_y = dy - y;
	int keylen = strlen(keys[loop]);

	//�ܾ �̾����� Ȯ��, �տ� �� �ܾ�� �̹� Ȯ��
	for (int v = 2; v < keylen; ++v) {
		if (x + (vector_x)*v >= m || y + (vector_y)*v >= n) return 0;
		if (x + (vector_x)*v < 0 || y + (vector_y)*v < 0) return 0;
		if (text[x + (vector_x)* v][y + (vector_y)* v] != keys[loop][v]) return 0;
	}
	printf("%d %d\n", x + 1, y + 1);
	return 1;
}

int isNextWord(int x, int y, char * text[MAXLEN], char * keys[MAXKEY], int loop, int m, int n) {
	//�ֺ� 8ĭ���� ���� �ܾ� ã��
	for (int i = x - 1; i <= x + 1; ++i) {
		if (i < 0) continue;

		for (int j = y - 1; j <= y + 1; ++j) {
			if (j < 0) continue;
			if (i == x && j == y) continue;	//�ڱ� �ڽ��� ����

			//���� �ܾ ��ġ�ϴ� ���
			if (text[i][j] == *(keys[loop] + 1)) {
				if (isRightVector(text, keys, x, y, i, j, loop, m, n)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

void FindWords(char * text[MAXLEN], int m, int n, char * keys[MAXKEY], int words) {
	int x, y;
	int isBreak;

	//�ܾ� �� ��ŭ �ݺ�
	for (int loop = 0; loop < words; ++loop) {
		isBreak = 0;

		//ù �ܾ� ã��
		for (int i = 0; i < m && !isBreak; ++i) {
			for (int j = 0; j < n; ++j) {
				//ù �ܾ ��ġ�ϴ� ���
				if (text[i][j] == *keys[loop]) {
					x = i; y = j;
					if(isNextWord(x, y, text, keys, loop, m, n))
						isBreak = 1; break;
				}
			}
		}
	}
}

int main() {
	int m, n, maxlen;
	int test, word;
	char * text[MAXLEN];
	char * keys[MAXKEY];

	scanf("%d", &test);

	//test��ŭ �ݺ�
	for (int i = 0; i < test; ++i) {
		scanf("%d %d", &m, &n);
		maxlen = m > n ? m : n;

		//MxN �׸��� �Է�
		while (getchar() != '\n');
		for (int j = 0; j < m; ++j) {
			text[j] = (char*)malloc(maxlen * sizeof(char*));

			fgets(text[j], n + 1, stdin);
			getchar();
			tolower(text[j]);
		}
		scanf("%d", &word);

		//Ű �ܾ� �Է�
		for (int j = 0; j < word; ++j) {
			keys[j] = (char*)malloc(maxlen * sizeof(char*));

			scanf("%s", keys[j]);
			tolower(keys[j]);
		}
		puts("");

		//�ܾ� ã��
		FindWords(text, m, n, keys, word);
	}

	return 0;
}

/*
1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcnqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
*/