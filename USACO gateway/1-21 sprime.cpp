/*
ID: lhs14381
LANG: C++14
TASK: sprime
*/

#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

static vector<int> prime = { 1,3,5,7,9 };
static set<int> sprime;
static int n;

bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

void generatePrimes(int num, int stage)
{
	if (stage == n)
	{
		num /= 10;

		if (!binary_search(sprime.begin(), sprime.end(), num))
			sprime.insert(num);
	}
	else
	{
		for (auto& p : prime)
		{
			num += p;
			if (isprime(num))
				generatePrimes(num * 10, stage + 1);
			num -= p;
		}
	}
}

void generateFirst()
{
	vector<int> prime = { 2,3,5,7 };

	for (auto& p : prime)
		generatePrimes(p * 10, 1);
}

int main()
{
	ifstream in("sprime.in");
	ofstream out("sprime.out");

	/* gets data */
	in >> n;

	/* algorithm */
	generateFirst();

	/* prints */
	for (auto& spnum : sprime)
		out << spnum << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}