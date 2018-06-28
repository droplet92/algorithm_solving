/*
ID: lhs14381
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fin = fopen("ride.in", "r");
	FILE * fout = fopen("ride.out", "w");
	char group[7] = { 0 };
	char comet[7] = { 0 };
	int sum1, sum2;
	int i;
	
	fscanf(fin, "%s %s", group, comet);
	sum1 = sum2 = 1;
	i = 0;
	while (group[i]) {
		sum1 *= group[i++] - 'A' + 1;
	}
	i = 0;
	while (comet[i]) {
		sum2 *= comet[i++] - 'A' + 1;
	}
	fprintf(fout, "%s\n", 
		sum1 % 47 == sum2 % 47 ?
	"GO" : "STAY");
	exit(0);
}