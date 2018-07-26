#include <stdio.h>
#define MAX 1000

int Round(double num, int floor) {
	if (num - floor > 0.0049)
		return num + 0.01;
	return num;
}

int main() {
	int n;
	double aver = 0, sum = 0, temp;
	double cost[MAX];

	while (1)
	{
		scanf("%d", &n);
		if (!n) break;

		for (int i = 0; i < n; ++i) {
			scanf("%lf", &cost[i]);
		}

		for (int i = 0; i < n; ++i) {
			aver += cost[i];
		}
		aver = Round(aver / n, aver / n);

		for (int i = 0; i < n; ++i) {
			temp = cost[i] - aver;
			if (temp < 0) sum -= temp;
		}
		printf("%.2f\n", sum);
	}
	return 0;
}