/*
ID: lhs14381
TASK: barn1
LANG: C++14
*/

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Foo {
	int idx;
	int gap;

	Foo(int a, int b) :
		idx(a), gap(b)
	{}
};

int main()
{
	ifstream in("barn1.in");
	ofstream out("barn1.out");

	int m, s, c;		// m: max can purchase, s: total of stalls, c: cows
	in >> m >> s >> c;

	if (m > c)
	{
		out << c << endl;
		return 0;
	}

	vector<int> cows;
	int temp;
	for (int i = 0; i < c; i++)
	{
		in >> temp;
		cows.push_back(temp);
	}
	sort(cows.begin(), cows.end());

	vector<Foo> v;
	int gap;
	for (int i = 1; i < c; i++)
	{
		gap = (cows[i] - cows[i - 1]);
		v.push_back(Foo(i - 1, gap));
	}
	sort(v.begin(), v.end(), [](Foo& lhs, Foo& rhs) {
		return lhs.gap > rhs.gap;
	});

	if (m > v.size())
	{
		sort(v.begin(), v.end() - 1, [](Foo& lhs, Foo& rhs) {
			return lhs.idx < rhs.idx;
		});
		(v.end() - 1)->idx = c - 1;
	}
	else
	{
		sort(v.begin(), v.begin() + (m - 1), [](Foo& lhs, Foo& rhs) {
			return lhs.idx < rhs.idx;
		});
		v[m - 1].idx = c - 1;
	}

	int beg = 0;
	int result;

	if (v.size() == 1)
	{
		if (m == 1) result = 1;
		else		result = 0;
	}
	else
		result = m;

	for (int i = 0; i < m && i < v.size(); i++)
	{
		result += cows[v[i].idx] - cows[beg];
		beg = v[i].idx + 1;
	}
	out << result << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}