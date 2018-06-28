#include <stdio.h>

int atoi(char c) {
	for (int i = 0; i < '9' - '0'; ++i) {
		if (c == '0' + i) return i;
	}
	return -1;
}

void main() {
	int n, before, abs;
	int arr[3000] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	before = arr[0];
	for (int i = 1; i < n; ++i) {
		abs = before - arr[i];
		if (abs < 0) abs = -abs;
		if (abs != n - i) {
			printf("Not jolly\n");
			return;
		}
		before = arr[i];
	}
	printf("Jolly\n");
}