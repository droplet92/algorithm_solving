#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN		9		/* 숫자 3 + space + 숫자 3 + enter + null */

int FindDepth(int n, int d) {
	if ((d == 0) || (d > n / 2)) return 0;			/* 최소 깊이 1, 최대 깊이 (n/2) */
	if ((d == 1) || (d == n / 2)) return 1;			/* 깊이가 1인 표현식은 1개 */
	return FindDepth(n - 2, d - 1) + FindDepth(n - 2, d) * 2;
}

int main() {
	int n;				/* 길이 */
	int d;				/* 깊이 */
	int result;			/* 결과값 */
	char text[MAXLEN];	/* 임시 문자열 */
	int i, j;			/* 카운터 */

	while (fgets(text, MAXLEN, stdin)) {
		//n과 d 입력
		text[strlen(text) - 1] = 0;
		if (!strlen(text)) continue;

		n = atoi(strtok(text, " "));
		d = atoi(strtok(NULL, " "));

		//계산
		if (n % 2) result = 0;
		else result = FindDepth(n, d);

		//수정 필요
		j = 0;
		if ((2 <= d) && (d <= n / 2 - 2)) {
			for (i = 3; i < (n / 2 - j); ++i, ++j)
				result -= (n / 2 - 3);
		}

		//결과 출력
		printf("%d\n", result);
	}
	return 0;
}