#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN	11

int Factovisors(int n, int m);

int main()
{
	int n, m;
	char temp[MAXLEN];

	while (fgets(temp, MAXLEN, stdin))
	{
		//n과 m 초기화
		n = atoi(strtok(temp, " "));
		m = atoi(strtok(NULL, "\n"));

		if (Factovisors(n, m) == 0)
			printf("%d divides %d!\n", m, n);
		else
			printf("%d does not divide %d!\n", m, n);
	}
	return 0;
}

int Factovisors(int n, int m)
{
	int i, temp = 1;
	for (i = n; i > 1; --i)
	{
		temp = (i*temp) % m;
	}
	return temp;
}

/*
6 9
6 27
20 10000
20 100000
1000 1009
*/