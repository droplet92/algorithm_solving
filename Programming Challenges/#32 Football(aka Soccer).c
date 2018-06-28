#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TORNAMENT_NAME	101
#define MAX_TEAM_NAME		31
#define MAX_TEAMS			30
#define MAX_RESULTS			(MAX_TEAM_NAME)*2 + 8
#define MAX_LISTS			(MAX_TEAM_NAME)+100

typedef struct {
	char name[MAX_TEAM_NAME];	/* �� �̸� */
	int wins;					/* �¸� */
	int draws;					/* ���º� */
	int loses;					/* �й� */
	int games;					/* ���� Ƚ�� */
	int pros;					/* ���� */
	int cons;					/* ���� */
	int points;					/* ���� */
} record;

void Init(char[], char[][MAX_TEAM_NAME], char[][MAX_RESULTS], int*, int*);
void GameResult(char[][MAX_TEAM_NAME], char[][MAX_RESULTS], char[][MAX_LISTS], int, int);
int compare_record(const void *a, const void *b);

int FindTeam(char * s, char teams[][MAX_TEAM_NAME])
{
	int i;

	for (i = 0; i < MAX_TEAMS; ++i) {
		if (!strcmp(s, teams[i])) return i;
	}
	return -1;
}

int main()
{
	char tor[MAX_TORNAMENT_NAME];			/* ��ʸ�Ʈ �̸� */
	char teams[MAX_TEAMS][MAX_TEAM_NAME];	/* �� ��� */
	char results[MAX_TEAMS][MAX_RESULTS];	/* ��� ��� */
	char list[MAX_TEAMS][MAX_LISTS];		/* ��� ���� ��� */
	int n, t, g;							/* �׽�Ʈ ���̽�, ��, ���� �� */
	int i, j;								/* ī���� */

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; ++i)
	{
		Init(tor, teams, results, &t, &g);
		printf("\n%s", tor);
		GameResult(teams, results, list, t, g);
	}
	return 0;
}

void Init(char tor[], char teams[][MAX_TEAM_NAME], char results[][MAX_RESULTS], int *t, int *g)
{
	int i;	/* ī���� */

	/* ��ʸ�Ʈ �̸� �Է� */
	fgets(tor, MAX_TORNAMENT_NAME, stdin);
	tor[strlen(tor) - 1] = 0;

	/* �� �Է� */
	scanf("%d", t);
	getchar();
	for (i = 0; i < *t; ++i)
	{
		fgets(teams[i], MAX_TEAM_NAME, stdin);
		teams[i][strlen(teams[i]) - 1] = 0;
	}

	/* ���� ��� �Է� */
	scanf("%d", g);
	getchar();
	for (i = 0; i < *g; ++i)
	{
		fgets(results[i], MAX_RESULTS, stdin);
		results[i][strlen(results[i]) - 1] = 0;
	}
}

void GameResult(char teams[][MAX_TEAM_NAME], char results[][MAX_RESULTS], 
				char list[][MAX_LISTS], int t, int g)
{
	record r[MAX_TEAMS];	/* ��� ��� */
	int teamL, teamR;		/* �� ���� �ε��� */
	int scoreL, scoreR;		/* �� ���� ���ھ� */
	int i, j;

	/* ��� �ʱ�ȭ */
	for (i = 0; i < t; ++i)
	{
		strcpy(r[i].name, teams[i]);
		r[i].wins = 0;
		r[i].draws = 0;
		r[i].loses = 0;
		r[i].points = 0;
		r[i].games = 0;
		r[i].pros = 0;
		r[i].cons = 0;
	}

	/* ��� �м� */
	for (i = 0; i < g; ++i)
	{
		teamL = FindTeam(strtok(results[i], "#@\n"), teams);
		scoreL = atoi(strtok(NULL, "#@\n"));
		scoreR = atoi(strtok(NULL, "#@\n"));
		teamR = FindTeam(strtok(NULL, "#@\n"), teams);

		r[teamL].pros += scoreL;
		r[teamL].cons += scoreR;
		r[teamR].pros += scoreR;
		r[teamR].cons += scoreL;
		++(r[teamL].games);
		++(r[teamR].games);

		/* L���� �̱� ��� */
		if (scoreL > scoreR) {
			r[teamL].points += 3;

			++(r[teamL].wins);
			++(r[teamR].loses);
		}
		/* R���� �̱� ��� */
		else if(scoreL < scoreR) {
			r[teamR].points += 3;

			++(r[teamR].wins);
			++(r[teamL].loses);
		}
		/* ��� ��� */
		else {
			r[teamL].points += 1;
			r[teamR].points += 1;

			++(r[teamL].draws);
			++(r[teamR].draws);
		}
	}
	qsort((record*)r, t, sizeof(record), compare_record);

	/* ��� ��� */
	for (i = 0; i < t; ++i)
	{
		printf("%d) %s %dp, ", (i+1), r[i].name, r[i].points);
		printf("%dg (%d-%d-%d), ", r[i].games, r[i].wins, r[i].draws, r[i].loses);
		printf("%dgd (%d-%d)\n", (r[i].pros)-(r[i].cons), r[i].pros, r[i].cons);
	}
	puts("");
}

int compare_record(const void *a, const void *b)
{
	record * lhs = (record*)a;
	record * rhs = (record*)b;

	if (lhs->points != rhs->points) return (rhs->points) - (lhs->points);
	return (lhs->games) - (rhs->games);	//���� ���� ���� ��
}

/*
2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D
*/