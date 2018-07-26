#include <stdio.h>
#define MAX 8
#define LCD 7

bool zero[LCD] = { 1,1,1,0,1,1,1 };
bool one[LCD] = { 0,0,1,0,0,1,0 };
bool two[LCD] = { 1,0,1,1,1,0,1 };
bool three[LCD] = { 1,0,1,1,0,1,1 };
bool four[LCD] = { 0,1,1,1,0,1,0 };
bool five[LCD] = { 1,1,0,1,0,1,1 };
bool six[LCD] = { 1,1,0,1,1,1,1 };
bool seven[LCD] = { 1,0,1,0,0,1,0 };
bool eight[LCD] = { 1,1,1,1,1,1,1 };
bool nine[LCD] = { 1,1,1,1,0,1,1 };

int pow(int a, int n) {
	int result = 1;
	for (int i = 0; i < n; ++i)
		result *= a;
	return result;
}

int InitSep(int(*sep)[MAX], int n) {
	int len;
	for (len = 1; len <= MAX; ++len) {
		if (!(n / pow(10, len))) break;
	}

	for (int i = 0; i < len; ++i) {
		(*sep)[i] = n / pow(10, len - i - 1) % 10;
	}
	return len;
}

bool isLightOn(int num, int order) {
	switch (num) {
	case 0: return zero[order];
	case 1: return one[order];
	case 2: return two[order];
	case 3: return three[order];
	case 4: return four[order];
	case 5: return five[order];
	case 6: return six[order];
	case 7: return seven[order];
	case 8: return eight[order];
	case 9: return nine[order];
	}
}

void LightLCD(bool lightOn, int s, int sepj, int *i) {
	bool next = isLightOn(sepj, *i + 1);

	if (*i == 0 || *i == 3 || *i == 6) {
		printf(" ");
		for (int a = 0; a < s; ++a) {
			if(lightOn) printf("-");
			else printf(" ");
		}
		printf(" ");
	}
	else {
		if (lightOn) printf("|");
		else printf(" ");

		for (int b = 0; b < s; ++b) {
			printf(" ");
		}
		if (next) printf("|");
		else printf(" ");
	}
}

void Print(int sep[], int len, int s) {
	int repeat;

	for (int i = 0; i < LCD; ++i) {
		if (i == 1 || i == 4) repeat = s;
		else repeat = 1;

		for (int k = 0; k < repeat; ++k) {
			for (int j = 0; j < len; ++j) {
				if (isLightOn(sep[j], i)) {
					LightLCD(true, s, sep[j], &i);
				}
				else {
					LightLCD(false, s, sep[j], &i);
				}
				printf(" ");
			}
			if (repeat == s) printf("\n");
		}
		if (repeat != s) printf("\n");

		if (i == 1 || i == 4) {
			++i;
		}
	}
}

int main() {
	int s, n, len;
	int sep[MAX] = { 0 };

	while (1) {
		scanf("%d %d", &s, &n);
		if (!s && !n) break;

		len = InitSep(&sep, n);
		Print(sep, len, s);
	}

	return 0;
}