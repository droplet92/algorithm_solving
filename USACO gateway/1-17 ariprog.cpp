/*
ID: lhs14381
LANG: C++14
TASK: ariprog
*/

#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define HEADBEGIN -1

struct point {
	int x, y;
	point(int x, int y) :
		x(x), y(y)
	{}
	friend bool operator==(const point& p1, const point& p2)
	{
		return (p1.x == p2.x) && (p1.y == p2.y);
	}
};

static int n, m;
static vector<point> v;
static unordered_set<int> board;

void bfs(int head = HEADBEGIN, int gap = 0)
{
	/* codiff always is greater than 0 */
	if (gap)
	{
		for (int i = (n - 1); i >= 2; i--)
		{
			if (board.find(head + gap * i) == board.end())
				return;
		}
		point res(head, gap);
		if (find(v.begin(), v.end(), res) == v.end())
			v.push_back(res);
	}
	else
	{
		for (int candidate : board)
		{
			if (head == HEADBEGIN)
			{
				if (candidate > (m*m - n + 1)) continue;
				bfs(candidate, 0);
			}
			else if ((gap = candidate - head) > 0)
			{
				if (head + gap * (n - 1) > 2 * m*m) continue;
				bfs(head, gap);
			}
		}
	}
}

int main()
{
	FILE* fin = fopen("ariprog.in", "r");
	FILE* fout = fopen("ariprog.out", "w");

	/* gets data */
	fscanf(fin, "%d %d", &n, &m);
	board.reserve(m*m);

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
			board.insert((i*i) + (j*j));
	}
	/* algorithm */
	bfs();

	/* prints */
	if (v.empty())
		fputs("NONE\n", fout);
	else
	{
		sort(v.begin(), v.end(), [](point& lhs, point& rhs) {
			return (lhs.y < rhs.y);
		});
		sort(v.begin(), v.end(), [](point& lhs, point& rhs) {
			return (lhs.y == rhs.y) && (lhs.x < rhs.x);
		});

		for (auto& iter : v)
			fprintf(fout, "%d %d\n", iter.x, iter.y);
	}

	/* closes */
	exit(0);
}