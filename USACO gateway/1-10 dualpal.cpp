/*
ID: lhs14381
TASK:dualpal
LANG: C++14
*/

#include <fstream>
#include <string>
using namespace std;

int pow(int base, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; i++) result *= base;
	return result;
}

string toString(int n, int& base)
{
	string result;
	int i = 0;

	while (1)
	{
		if (n / pow(base, i) == 0)
			break;

		i++;
	}
	int temp;

	for (int j = (i - 1); j >= 0; j--)
	{
		temp = pow(base, j);
		result += (n / temp >= 10) ?
			string(1, 'A' + (n / temp) % 10) : to_string(n / temp);
		n %= temp;
	}
	return result;
}

bool isPallindrome(int& n, int& base)
{
	string s = toString(n, base);
	int len = s.length();

	for (int i = 0; i < (len / 2); i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

int main()
{
	ifstream in("dualpal.in");
	ofstream out("dualpal.out");

	int n, s;
	int cnt = 0;
	int endcnt = 0;

	in >> n >> s;

	for (int i = (s + 1); endcnt != n; i++)
	{
		cnt = 0;
		for (int base = 2; base <= 10; base++)
		{
			if (isPallindrome(i, base))
				++cnt;

			if (cnt == 2)
			{
				out << i << endl;
				++endcnt;
				break;
			}
		}
	}

	/* closes files */
	in.close(), out.close();
	return 0;
}