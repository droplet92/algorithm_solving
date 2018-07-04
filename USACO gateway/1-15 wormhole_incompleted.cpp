/*
ID: lhs14381
TASK: wormhole
LANG: C++14
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Column {
	int ypos;
	int num;

	Column(int y) :
		ypos(y), num(1)
	{}
};

struct Point {
	int xpos, ypos;

	Point(int x, int y) :
		xpos(x), ypos(y)
	{}

	inline bool operator==(const Point& p)
	{
		return xpos == p.xpos &&
			ypos == p.ypos;
	}
	inline bool operator!=(const Point& p)
	{
		return !operator==(p);
	}
};

int factorial(int n)
{
	int result = 1;
	while (n > 0)
		result *= (n--);
	return result;
}

inline int permu(int n, int r)
{
	return factorial(n) / factorial(n - r);
}

inline int combi(int n, int r)
{
	return permu(n, r) / factorial(r);
}

static int n;
static vector<Column> v;
static vector<vector<Point>> recur;

#include <iostream>

void recursive(vector<Point>& choosen, int* used, int stage = 0)
{
	const int max = n - 2;

	if (choosen.size() == (max / 2))
	{
		sort(choosen.begin(), choosen.end(), [](Point& p1, Point& p2) {
			if (p1.xpos < p2.xpos) return true;
			if (p1.xpos == p2.xpos &&
				p1.ypos < p2.ypos) return true;
			return false;
		});
		auto res = find_if(choosen.begin(), choosen.end(), [](Point& p) {
			return abs(p.xpos - p.ypos) == 1;
		});
		if (res == choosen.end())
		{
			res = find_if(choosen.begin(), choosen.end(), [&](Point& p) {
				for (int i = 4; i <= max; i += 2)
				{
					if (p.ypos - p.xpos == i - 1)
					{
						for (auto& c : choosen)
						{
							if (c == p) continue;
							if (((res->xpos < c.xpos && c.xpos < res->ypos) && c.ypos > res->ypos) ||
								(res->xpos > c.xpos && (res->xpos < c.ypos && c.ypos < res->ypos)))
							{
								return false;
							}
						}
						return true;
					}
				}
				return false;
			});
			if (res == choosen.end())
				return;
		}
		if (res != choosen.end())
		{
			auto res = find_if(recur.begin(), recur.end(), [&choosen](vector<Point>& v) {
				int size = v.size();
				for (int i = 0; i < size; i++)
				{
					if (v[i] != choosen[i])
						return false;
				}
				return true;
			});
			if (res == recur.end())
			{
				recur.push_back(choosen);
				for (auto& c : choosen)
					cout << c.xpos << ',' << c.ypos << ' ';
				cout << endl;
			}
		}
		return;
	}
	for (int i = 1; i <= max; i++)
	{
		for (int j = (i + 1); j <= max; j++)
		{
			if (used[i] || used[j]) continue;
			if (i == j) continue;
			used[i] = used[j] = 1;

			choosen.emplace_back(Point(i, j));
			recursive(choosen, used, stage + 1);

			used[choosen.rbegin()->xpos] = 0;
			used[choosen.rbegin()->ypos] = 0;
			choosen.pop_back();
		}
	}
}

int getSum()
{
	int sum = 0;

	if (v.size() == 1)
	{
		if ((n - v.begin()->num) == 1)
		{
			vector<Point> empty;
			empty.reserve(n - 2);
			int* used = new int[n - 1]{ 0 };
			recursive(empty, used);
			sum = (v.begin()->num)*recur.size();
		}
		else
		{
			sum = v.begin()->num - 1;
			for (int i = (n - 2); i > 0; i -= 2)
				sum *= permu(i, 2) / i;
		}
	}
	else
	{
		int temp;
		for (auto& p : v)
		{
			temp = combi(p.num, 2);
			for (int i = (n - 2); i > 0; i -= 2)
				temp *= permu(i, 2) / i;
			sum += temp;
		}
	}
	return sum;
}

int main()
{
	ifstream in("wormhole.in");
	ofstream out("wormhole.out");

	/* gets inputs */
	in >> n;

	int x, y;
	for (int i = 0; i < n; i++)
	{
		in >> x >> y;
		auto res = find_if(v.begin(), v.end(), [&y](Column& p) {
			return p.ypos == y;
		});

		if (res == v.end())
			v.push_back(Column(y));
		else
			++(res->num);
	}
	/* algorithm */
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].num < 2)
		{
			v.erase(v.begin() + i);
			--i;
		}
	}
	out << getSum() << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}