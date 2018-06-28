/*
ID: lhs14381
TASK: combo
LANG: C++14
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

static vector<vector<int>> solutions;

/* set boundary: (0, max] */
int wrap_around(int n, int max)
{
	if (n > max)
		return (n - max);
	else if (n <= 0)
		return (n + max);
	return n;
}

void init(ifstream& in, vector<int>& v)
{
	string buf;
	int end;

	getline(in, buf);

	while (1)
	{
		if ((end = buf.find_first_of(' ')) == string::npos)
		{
			v.push_back(stoi(buf));
			return;
		}
		v.push_back(stoi(buf.substr(0, end)));
		buf = buf.substr(end + 1);
	}
}

void generate(int stage, int n, int max, vector<int>& sol, vector<int>& set)
{
	if (stage == n)
	{
		if (find(solutions.begin(), solutions.end(), set)
			== solutions.end())
		{
			for (auto& v : set)
				cout << v << ' ';
			cout << endl;
			solutions.push_back(set);
		}
	}
	else
	{
		int elem;
		for (int j = -2; j <= 2; j++)
		{
			elem = wrap_around(sol[stage] + j, max);
			if (elem == 0 || elem > max) continue;
			set.push_back(elem);
			generate(stage + 1, n, max, sol, set);
			set.pop_back();
		}
	}
}

int main()
{
	ifstream in("combo.in");
	ofstream out("combo.out");

	int n;
	in >> n;
	in.get();

	vector<int> john;
	vector<int> master;

	init(in, john);
	init(in, master);

	vector<int> emptyset;
	generate(0, john.size(), n, john, emptyset);
	generate(0, master.size(), n, master, emptyset);

	out << solutions.size() << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}