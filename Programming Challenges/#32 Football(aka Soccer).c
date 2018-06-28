#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TORNAMENT_NAME	101
#define MAX_TEAM_NAME		31
#define MAX_TEAMS			30
#define MAX_RESULTS			(MAX_TEAM_NAME)*2 + 8
#define MAX_LISTS			(MAX_TEAM_NAME)+100

typedef struct {
	char name[MAX_TEAM_NAME];	/* 팀 이름 */
	int wins;					/* 승리 */
	int draws;					/* 무승부 */
	int loses;					/* 패배 */
	int games;					/* 게임 횟수 */
	int pros;					/* 득점 */
	int cons;					/* 실점 */
	int points;					/* 승점 */
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
	char tor[MAX_TORNAMENT_NAME];			/* 토너먼트 이름 */
	char teams[MAX_TEAMS][MAX_TEAM_NAME];	/* 팀 목록 */
	char results[MAX_TEAMS][MAX_RESULTS];	/* 결과 목록 */
	char list[MAX_TEAMS][MAX_LISTS];		/* 결과 정리 목록 */
	int n, t, g;							/* 테스트 케이스, 팀, 게임 수 */
	int i, j;								/* 카운터 */

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
	int i;	/* 카운터 */

	/* 토너먼트 이름 입력 */
	fgets(tor, MAX_TORNAMENT_NAME, stdin);
	tor[strlen(tor) - 1] = 0;

	/* 팀 입력 */
	scanf("%d", t);
	getchar();
	for (i = 0; i < *t; ++i)
	{
		fgets(teams[i], MAX_TEAM_NAME, stdin);
		teams[i][strlen(teams[i]) - 1] = 0;
	}

	/* 게임 결과 입력 */
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
	record r[MAX_TEAMS];	/* 경기 기록 */
	int teamL, teamR;		/* 두 팀의 인덱스 */
	int scoreL, scoreR;		/* 두 팀의 스코어 */
	int i, j;

	/* 기록 초기화 */
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

	/* 결과 분석 */
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

		/* L팀이 이긴 경우 */
		if (scoreL > scoreR) {
			r[teamL].points += 3;

			++(r[teamL].wins);
			++(r[teamR].loses);
		}
		/* R팀이 이긴 경우 */
		else if(scoreL < scoreR) {
			r[teamR].points += 3;

			++(r[teamR].wins);
			++(r[teamL].loses);
		}
		/* 비긴 경우 */
		else {
			r[teamL].points += 1;
			r[teamR].points += 1;

			++(r[teamL].draws);
			++(r[teamR].draws);
		}
	}
	qsort((record*)r, t, sizeof(record), compare_record);

	/* 결과 출력 */
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
	return (lhs->games) - (rhs->games);	//게임 수는 적은 쪽
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