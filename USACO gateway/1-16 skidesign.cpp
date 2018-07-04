/*
ID: lhs14381
LANG: C++14
TASK: skidesign
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_DIFF = 17;
static vector<int> hills;
static int n;
static int mincost = INT32_MAX;

int main()
{
	ifstream in("skidesign.in");
	ofstream out("skidesign.out");

	/* gets data */
	in >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		in >> temp;
		hills.push_back(temp);
	}
	sort(hills.begin(), hills.end());

	/* algorithm */
	int ubound;
	int cost;
	int last = *hills.rbegin();

	for (int ref = 0; ref < last; ref++)
	{
		ubound = (ref + MAX_DIFF);
		cost = 0;

		for (auto& h : hills)
		{
			if (h < ref)
				cost += (ref - h)*(ref - h);

			else if (ubound < h)
				cost += (h - ubound)*(h - ubound);
		}
		mincost = min(mincost, cost);
	}

	out << mincost << endl;

	/* closes file streams */
	in.close(), out.close();
	return 0;
}