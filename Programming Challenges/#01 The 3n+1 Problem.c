#include <stdio.h>

int GetCycleLength(int n) {
	int i;
	for (i = 1; n != 1; ++i) {
		if (n % 2) {
			n = n * 3 + 1;
		}
		else {
			n /= 2;
		}
	}
	return i;
}

int main() {
	int i, j;
	int temp, max = 0;

	scanf("%d %d", &i, &j);

	for (int n = i; n <= j; ++n) {
		temp = GetCycleLength(n);
		max = max > temp ? max : temp;
	}
	printf("%d %d %d\n", i, j, max);
	return 0;
}