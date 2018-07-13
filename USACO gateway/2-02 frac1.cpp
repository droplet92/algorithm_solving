/*
ID: lhs14381
LANG: C++14
TASK: frac1
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

struct fraction
{
	int numer;
	int denom;

	fraction(int n, int d)
	{
		int divisor = gcd(n, d);
		numer = n / divisor;
		denom = d / divisor;
	}
	bool operator==(const fraction& f) {
		return (numer / denom) == (f.numer / f.denom);
	}
	friend bool operator<(const fraction& f1, const fraction& f2) {
		return ((double)f1.numer / f1.denom) < ((double)f2.numer / f2.denom);
	}
	void print(ofstream& out) {
		out << numer << '/' << denom << endl;
	}
};

int main()
{
	ifstream in("frac1.in");
	ofstream out("frac1.out");

	/* gets data */
	int n;
	in >> n;

	/* algorithm */
	set<fraction> flist;
	int i, j;

	flist.insert(fraction(0, 1));
	flist.insert(fraction(1, 1));
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
			flist.insert(fraction(j, i));
	}

	/* prints */
	for (auto frac : flist)
		frac.print(out);

	/* closes */
	in.close(), out.close();
	return 0;
}