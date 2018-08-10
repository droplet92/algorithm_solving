/*
ID: lhs14381
LANG: C++14
TASK: prefix
*/

#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream in("prefix.in");
ofstream out("prefix.out");

vector<string> prefix;
string s;
bool cache[200001];

int main()
{
	/* gets data */
	string word;

	in >> word;
	while (word != ".")
	{
		prefix.push_back(word);
		in >> word;
	}

	do
	{
		word.clear();
		in >> word;
		s += word;
	} while (word.size());

	/* algorithm */
	int i, j;
	int maxlen = 0;
	int size = s.size();
	cache[0] = true;

	for (i = 0; i < size; i++)
	{
		if (cache[i])
		{
			maxlen = i;

			for (auto& p : prefix)
			{
				/* s.sub(i).find(p) */
				for (j = 0; (i + j < size) && (p[j] && p[j] == s[i + j]); j++)
					;
				if (!p[j])
					cache[i + j] = true;
			}
		}
	}

	if (cache[size])
		maxlen = size;

	/* prints */
	out << maxlen << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}