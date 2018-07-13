/*
ID: lhs14381
LANG: C++14
TASK: holstein
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define VMAX	25
#define GMAX	15
#define NUMMAX	1001

static int type[VMAX];
static vector<int> scoop[GMAX];
static vector<int> solution;
static int v, g;

void backtrack(int stage, int nloop, int* arr, int* footprint)
{
	int i;

	if (stage == nloop)
	{
		for (i = 0; i < v; i++)
		{
			if (arr[i] < type[i] || (solution.size() && arr[i] > solution[i]))
				return;
		}
		for (i = 0; i <= nloop; i++)
			solution.push_back(footprint[i] + 1);
	}
	else
	{
		int j;
		int next[VMAX];
		int nextstep[GMAX];

		memcpy(nextstep, footprint, sizeof(int)*g);
		++stage;

		/* number */
		for (i = (footprint[stage - 1] + 1); i < g; i++)
		{
			nextstep[stage] = i;

			for (j = 0; j < v; j++)
				next[j] = (arr[j] + scoop[i][j]);
			backtrack(stage, nloop, next, nextstep);
		}
	}
}

int generate()
{
	int i, j, k;
	int arr[VMAX];
	int footprint[GMAX] = { 0 };

	/* nloop */
	for (i = 0; i < g; i++)
	{
		/* number */
		for (j = 0; j < g; j++)
		{
			memset(arr, 0, sizeof(int)*VMAX);
			footprint[0] = j;

			for (k = 0; k < v; k++)
				arr[k] += scoop[j][k];
			backtrack(0, i, arr, footprint);

			if (solution.size())
				return i + 1;
		}
	}
	return -1;
}

int main()
{
	ifstream in("holstein.in");
	ofstream out("holstein.out");

	/* gets data */
	int i, j, temp;
	in >> v;
	solution.reserve(v);

	for (i = 0; i < v; i++)
	{
		in >> type[i];
	}

	in >> g;
	for (i = 0; i < g; i++)
	{
		for (j = 0; j < v; j++)
		{
			in >> temp;
			scoop[i].push_back(temp);
		}
	}

	/* algorithm */
	out << generate();

	/* prints */
	for (auto& s : solution)
		out << ' ' << s;
	out << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}