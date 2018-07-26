/*
ID: lhs14381
LANG: C++14
TASK: runround
*/

#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

static const int maxnum = 10;

static ifstream in("runround.in");
static ofstream out("runround.out");

static vector<int> v;

// next = (present + remain) % size
// if (remain == 0), corresponding number substitudes
void runaround()
{
	int foo[maxnum];
	int bar;

	do
	{
		memset(foo, 0, sizeof(int)*maxnum);
		for (int i = 0, next = 0; i < v.size(); i++)
		{
			next = (next + v[next] % v.size()) % v.size();
			if (foo[v[next]]) goto NEXT;
			foo[v[next]] = 1;
		}
		return;
	NEXT:
		for (auto riter = v.rbegin(); riter != v.rend(); ++riter)
		{
			++(*riter);
			if (*riter == 10)
			{
				*riter = 1;
				if (riter == v.rend() - 1)
				{
					v.insert(v.begin(), 1);
					break;
				}
				continue;
			}
			else
				break;
		}
	} while (true);
}

int main()
{
	/* gets data */
	int m;
	in >> m;
	m += 1;

	for (int i = log10(m); i >= 0; i--)
	{
		v.push_back(m / pow(10, i));
		m %= (int)pow(10, i);
	}

	/* algorithm */
	runaround();

	/* prints */
	for (auto& t : v)
		out << t;
	out << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}