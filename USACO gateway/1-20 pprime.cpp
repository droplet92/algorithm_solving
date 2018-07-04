/*
ID: lhs14381
LANG: C++14
TASK: pprime
*/

#include <fstream>
#include <functional>
#include <set>
#include <cmath>
using namespace std;

static set<int> pprime;
static int lbound, ubound;

int pow(int base, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; i++)
		result *= base;
	return result;
}

bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int func(int n, int lower, int upper)
{
	int temp = n * (pow(10, (upper - 1)*2 - lower) + pow(10, lower));
	if (lower == (upper - 1)) return temp / 2;
	return temp;
}

void generatePalindrome(int stage, int cipher, int num, function<int(int, int, int)> f)
{
	if (num > ubound) return;

	if (stage == cipher)
	{
		if (isprime(num) && num >= lbound)
			pprime.insert(num);
	}
	else
	{
		int cur;
		for (int i = 0; i <= 9; i++)
		{
			if (i % 2 == 0 && stage == 0)
				continue;
			if (stage == cipher - 1)
			{
				cur = num % pow(10, cipher);
				if (cur + i * pow(10, cipher - 1) >= pow(10, cipher))
					continue;
			}
			generatePalindrome(stage + 1, cipher, num + f(i, stage, cipher), f);
		}
	}
}

void generateFirst()
{
	int ucipher = (int)log10(ubound) / 2 + 1;

	if (lbound == 5)
		pprime.insert(5);

	if (lbound <= 7 && ubound >= 7)
		pprime.insert(7);

	if (lbound <= 11 && ubound >= 11)
		pprime.insert(11);

	for (int cipher = 1; cipher <= ucipher; cipher++)
		generatePalindrome(0, cipher, 0, func);
}

int main()
{
	ifstream in("pprime.in");
	ofstream out("pprime.out");

	/* gets data */
	in >> lbound >> ubound;

	/* algorithm */
	generateFirst();

	/* prints */
	for (auto& pnum : pprime)
		out << pnum << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}