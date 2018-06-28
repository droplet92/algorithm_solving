/*
ID: lhs14381
TASK: crypt1
LANG: C++14
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	abc
X	 de
-------
	***
   ***
-------
   ****

abc * d, abc * e, abc * de
*/

const int maxlen = 5;
static int len;			// a size of sets
static int cnt;			// a number of solution sets

int pow(int base, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; i++) result *= base;
	return result;
}

bool inSet(int* set, char elem)
{
	for (int i = 0; i < len; i++)
	{
		if ((set[i] + '0') == elem)
			return true;
	}
	return false;
}

bool inSet(int* dom, string& s)
{
	for (auto& c : s)
	{
		if (!inSet(dom, c))
			return false;
	}
	return true;
}
#include <iostream>

/* dom: domain, cand: candidate */
bool isSolution(int* dom, int* cand)
{
	int d = cand[3];
	int e = cand[4];
	int abc = (cand[0] * 100) + (cand[1] * 10) + cand[2];
	int de = (d * 10) + e;

	string abc_d = to_string(abc*d);
	if (abc_d.size() != 3) return false;

	string abc_e = to_string(abc*e);
	if (abc_e.size() != 3) return false;
	
	string abcde = to_string(abc*de);

	if (!inSet(dom, abc_d)) return false;
	if (!inSet(dom, abc_e)) return false;
	if (!inSet(dom, abcde)) return false;
	return true;
}
#include <iostream>
static vector<vector<int>> v;

void Recursive(int stage, int* set, int* sol)
{
	if (stage == maxlen)
	{
		if (isSolution(set, sol))
			++cnt;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			sol[stage] = set[i];
			Recursive(stage + 1, set, sol);
		}
	}
}

int main()
{
	ifstream in("crypt1.in");
	ofstream out("crypt1.out");

	in >> len;

	int* set = new int[len];
	for (int i = 0; i < len; i++)
		in >> set[i];

	/* makes sets */
	int solution[maxlen];
	Recursive(0, set, solution);

	out << cnt << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}