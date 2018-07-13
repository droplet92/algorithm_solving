/*
ID: lhs14381
LANG: C
TASK: castle
*/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b)	((a) > (b) ? (a) : (b))

#define MAX_ROOM	50
#define WEST		0b0001
#define NORTH		0b0010
#define EAST		0b0100
#define SOUTH		0b1000

typedef struct {
	short graphnum;
	short walls;			// south, east, north, west
} vertex;

typedef struct {
	int xpos, ypos;
	int area;
	char dir;
} wall;

static int row, col;
vertex table[MAX_ROOM][MAX_ROOM];

static int nroom;
static int gsize[MAX_ROOM*MAX_ROOM + 1];

void dfs(int depth, int x, int y)
{
	if (table[x][y].graphnum) return;
	if (depth == 0) ++nroom;
	++gsize[nroom];
	table[x][y].graphnum = nroom;

	if ((table[x][y].walls & WEST) != WEST)
		dfs(depth + 1, x, y - 1);

	if ((table[x][y].walls & NORTH) != NORTH)
		dfs(depth + 1, x - 1, y);

	if ((table[x][y].walls & EAST) != EAST)
		dfs(depth + 1, x, y + 1);

	if ((table[x][y].walls & SOUTH) != SOUTH)
		dfs(depth + 1, x + 1, y);
}

void merge(wall* delwall)
{
	wall stack[MAX_ROOM*MAX_ROOM*2];
	int i, j, k = 0;

	for (i = 0; i < col; i++)
	{
		for (j = (row - 1); j >= 0; j--)
		{
			if (j > 0 && (table[j][i].graphnum != table[j - 1][i].graphnum))
			{
				stack[k].xpos = j + 1;
				stack[k].ypos = i + 1;
				stack[k].area = gsize[table[j][i].graphnum] + gsize[table[j - 1][i].graphnum];
				stack[k].dir = 'N';
				k++;
			}
			if (i < (col - 1) && (table[j][i].graphnum != table[j][i + 1].graphnum))
			{
				stack[k].xpos = j + 1;
				stack[k].ypos = i + 1;
				stack[k].area = gsize[table[j][i].graphnum] + gsize[table[j][i + 1].graphnum];
				stack[k].dir = 'E';
				k++;
			}
		}
	}

	int maxarea = 0;
	wall iter;
	for (i = 0; i < k; i++)
	{
		iter = stack[i];

		if (maxarea < iter.area)
		{
			maxarea = iter.area;
			delwall->xpos = iter.xpos;
			delwall->ypos = iter.ypos;
			delwall->area = iter.area;
			delwall->dir = iter.dir;
		}
	}
}

void main()
{
	FILE* in = fopen("castle.in", "r");
	FILE* out = fopen("castle.out", "w");

	fscanf(in, "%d %d", &col, &row);

	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			table[i][j].graphnum = 0;
			fscanf(in, "%hd", &table[i][j].walls);
		}
	}
	fclose(in);

	/* init graphs and find nroom */
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			dfs(0, i, j);
	}
	/* find the largest room size */
	volatile int lsize = 0;
	for (i = 1; i <= nroom; i++)
		lsize = max(lsize, gsize[i]);

	/* find a wall to remove */
	wall delwall;
	merge(&delwall);

	/* print */
	fprintf(out, "%d\n", nroom);
	fprintf(out, "%d\n", lsize);
	fprintf(out, "%d\n", delwall.area);
	fprintf(out, "%d %d %c\n", delwall.xpos, delwall.ypos, delwall.dir);

	fclose(out);
	exit(0);
}