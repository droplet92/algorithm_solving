/*
ID: lhs14381
TASK: milk2
LANG: C++14
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Pos {
	int begin, end;

	Pos(int x, int y):
		begin(x),
		end(y)
	{}

	inline int length() const { return end - begin; }
	bool isSubspace(const Pos& p)
	{
		if (p.begin > begin)	return false;
		if (p.end < end)		return false;
		return true;
	}
} pos;

int main()
{
	ifstream in("milk2.in");
	ofstream out("milk2.out");

	vector<pos> v;
	int len, beg, end;
	int idx;

	in >> len;

	// reads lines
	while (in.good())
	{
		in >> beg >> end;
		v.push_back(pos(beg, end));
	}
	// erases all subspaces
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j) continue;

			if (v[i].isSubspace(v[j]))
			{
				v.erase(v.begin() + i);
				--i;
				break;
			}
		}
	}
	sort(v.begin(), v.end(), [](pos& lhs, pos& rhs) {
		return lhs.begin < rhs.begin;
	});
	// combines
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j) continue;

			else if (v[i].begin <= v[j].begin && v[j].begin <= v[i].end)
			{
				v[i].end = v[j].end;
				v.erase(v.begin() + j);
				--j;
			}
			else if (v[i].begin <= v[j].end && v[j].end <= v[i].end)
			{
				v[i].begin = v[j].begin;
				v.erase(v.begin() + j);
				--j;
			}
		}
	}
	// finds maximums
	int maxfeed = 0, maxbreak = 0;
	int s = v.size();

	for (int i = 0; i < s; i++)
	{
		maxfeed = maxfeed > v[i].length() ?
			maxfeed : v[i].length();
	}
	for (int i = 1; i < s; i++)
	{
		maxbreak = maxbreak > v[i].begin - v[i - 1].end ?
			maxbreak : v[i].begin - v[i - 1].end;
	}
	// writes data to file
	out << maxfeed << ' ' << maxbreak << endl;
	return 0;
}