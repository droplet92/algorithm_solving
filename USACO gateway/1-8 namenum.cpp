/*
ID: lhs14381
TASK: namenum
LANG: C++14
*/

#include <fstream>
#include <string>
using namespace std;

static int cnt;

bool find(string map, char target)
{
	for (int i = 0; i < 3; i++)
	{
		if (map[i] == target)
			return true;
	}
	return false;
}

bool det(string nums, string line)
{
	string tkeypad[] = {
		"ABC", "DEF", "GHI",
		"JKL", "MNO", "PRS",
		"TUV", "WXY"
	};
	int len = nums.size() - 1;	// compiler bug?

	for (int i = 0; i < len; i++)
	{
		if (find(tkeypad[nums[i] - '0' - 2], line[i]))
			continue;

		return false;
	}
	return true;
}

int main()
{
	ifstream in("namenum.in");
	ofstream out("namenum.out");

	string nums;

	while (in.good())
		nums.push_back(in.get());

	nums.pop_back();

	ifstream dict("dict.txt");
	string line;

	while (dict.good())
	{
		getline(dict, line);

		if (det(nums, line))
		{
			out << line << endl;
			++cnt;
		}
	}
	if (!cnt)
		out << "NONE" << endl;

	/* closes files */
	dict.close();
	in.close(), out.close();
	return 0;
}