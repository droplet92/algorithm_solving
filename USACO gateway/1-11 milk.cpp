/*
ID: lhs14381
TASK: milk
LANG: C++14
*/

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Farmer {
	int cost;
	int unit;
};

int main()
{
	ifstream in("milk.in");
	ofstream out("milk.out");

	int n, m;		// n: wants per day, m: farmers
	in >> n >> m;

	vector<Farmer> v;
	for (int i = 0; i < m; i++)
	{
		Farmer f;
		in >> f.cost >> f.unit;
		v.push_back(f);
	}

	sort(v.begin(), v.end(), [](Farmer& lhs, Farmer& rhs) {
		return lhs.cost < rhs.cost;
	});

	int result = 0;
	int units = 0;
	for (auto& farmer : v)
	{
		if (farmer.unit > n - units)
		{
			result += (farmer.cost)*(n - units);
			break;
		}
		result += (farmer.cost)*(farmer.unit);
		units += farmer.unit;
	}
	out << result << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}