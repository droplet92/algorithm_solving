#include <stdio.h>
#define MAX_PEOPLE 20
#define MAX_NAME 80
#define MAX_VOTE 1000

void GetMax(int* max, int* count, int voted[MAX_PEOPLE], int n) {
	*max = voted[0];

	for (int i = 1; i < n; ++i) {
		if (*max < voted[i]) {
			*max = voted[i];
			*count = 1;
		}
		else if (*max == voted[i]) ++*count;
	}
}

void GetMin(int* min, int* count, int voted[MAX_PEOPLE], int n) {
	*min = voted[0];

	for (int i = 1; i < n; ++i) {
		if (*min > voted[i]) {
			*min = voted[i];
			*count = 1;
		}
		else if (*min == voted[i]) ++*count;
	}
}

int reverse(int *voted, int val, int begin, int v_num) {
	for (int i = begin + 1; i < v_num; ++i) {
		if (voted[i] == val) return i;
	}
}

void CountBallots(int vote[MAX_VOTE][MAX_PEOPLE], 
	char people[MAX_PEOPLE][MAX_NAME], int v_num, int p_num)
{
	int voted[MAX_PEOPLE] = { 0 };
	int max = 0, min = 0, i = 0;
	int max_count = 1, min_count = 1;

	do { //몇 순위 후보
		for (int j = 0; j < v_num; ++j) {	//투표함 개봉
			if (!min || vote[j][i-1] == reverse(voted, min, -1, v_num) + 1)
				++voted[vote[j][i] - 1];
		}
		//max, min
		GetMax(&max, &max_count, voted, p_num);
		GetMin(&min, &min_count, voted, p_num);

		//max가 단독, 과반수면 return
		if (max_count == 1 && max > v_num / 2) {
			printf("%s", people[reverse(voted, max, -1, v_num)]);
			return;
		}
		//동률이면 동률인 모든 후보 return
		else if (max_count > 1 && max == v_num / 2) {
			int temp = -1;

			for (int j = 0; j < max_count; ++j) {
				temp = reverse(voted, max, temp, v_num);
				printf("%s", people[temp]);
			}
			return;
		}
		//아니면 min의 차순위 후보 개봉
		else {
			++i;
			max_count = 1;
			min_count = 1;
		}
	} while (true);
}

int main() {
	int case_num, n;
	int vote[MAX_VOTE][MAX_PEOPLE] = { 0 };
	char people[MAX_PEOPLE][MAX_NAME];
	
	scanf("%d\n", &case_num);
	for (int k = 0; k < case_num; ++k) {
		scanf("%d", &n);
		getchar();

		for (int i = 0; i < n; ++i) {
			fgets(people[i], MAX_NAME, stdin);
		}

		//입력받지 말아야 함
		int i, repeat;
		scanf("%d", &repeat);

		for (i = 0; i < repeat; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%c", &vote[i][j]);
			}
			++i;
		}
		puts("");
		CountBallots(vote, people, i, n);

	}
	return 0;
}