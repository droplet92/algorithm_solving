/*
ID: lhs14381
TASK: palsquare
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
	string s = toString(n*n, base);
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
	ifstream in("palsquare.in");
	ofstream out("palsquare.out");

	string n;
	getline(in, n);

	int base = stoi(n);

	for (int i = 1; i <= 300; i++)
	{
		if (isPallindrome(i, base))
		{
			out << toString(i, base) << ' ';
			out << toString(i * i, base) << endl;
		}
	}

	/* closes files */
	in.close(), out.close();
	return 0;
}