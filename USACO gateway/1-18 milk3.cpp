/*
ID: lhs14381
LANG: C++14
TASK: milk3
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

static int a, b, c;
static vector<int> bucket;

void backtrack(int anow, int bnow, int cnow, vector<vector<int>>& v)
{
	if (anow == 0 && bnow != 0)
	{
		if (find(bucket.begin(), bucket.end(), cnow) == bucket.end())
			bucket.push_back(cnow);
	}
	vector<int> elem = { anow, bnow, cnow };
	if (find(v.begin(), v.end(), elem) != v.end())
		return;
	v.push_back(elem);

	int overflow;

	if (anow < a)
	{
		/* from b to a */
		if (bnow > 0)
		{
			if ((overflow = bnow - (a - anow)) < 0)
				overflow = 0;
			backtrack(min(a, anow + bnow), overflow, cnow, v);
		}
		/* from c to a */
		if (cnow > 0)
		{
			if ((overflow = cnow - (a - anow)) < 0)
				overflow = 0;
			backtrack(min(a, anow + cnow), bnow, overflow, v);
		}
	}
	if (bnow < b)
	{
		/* from a to b */
		if (anow > 0)
		{
			if ((overflow = anow - (b - bnow)) < 0)
				overflow = 0;
			backtrack(overflow, min(b, bnow + anow), cnow, v);
		}
		/* from c to b */
		if (cnow > 0)
		{
			if ((overflow = cnow - (b - bnow)) < 0)
				overflow = 0;
			backtrack(anow, min(b, bnow + cnow), overflow, v);
		}
	}
	if (cnow < c)
	{
		/* from a to c */
		if (anow > 0)
		{
			if ((overflow = anow - (c - cnow)) < 0)
				overflow = 0;
			backtrack(overflow, bnow, min(c, cnow + anow), v);
		}
		/* from b to c */
		if (bnow > 0)
		{
			if ((overflow = bnow - (c - cnow)) < 0)
				overflow = 0;
			backtrack(anow, overflow, min(c, cnow + bnow), v);
		}
	}
}

int main()
{
	ifstream in("milk3.in");
	ofstream out("milk3.out");

	/* gets data */
	in >> a >> b >> c;
	bucket.push_back(c);

	/* algorithm */
	vector<vector<int>> empty;
	backtrack(0, 0, c, empty);

	/* prints */
	sort(bucket.begin(), bucket.end());
	for (auto iter = bucket.begin(); iter != bucket.end(); ++iter)
	{
		if (iter == (bucket.end() - 1))
			out << *iter << endl;
		else
			out << *iter << ' ';
	}

	/* closes */
	exit(0);
}