/*
ID: lhs14381
TASK: transform
LANG: C++14
*/

#include <fstream>
#include <cstring>
using namespace std;

class SquarePattern
{
public:
	char before[10][10];
	char after[10][10];
	int n, len;

	SquarePattern()
	{
		memset(before, 0, 10 * 10);
		memset(after, 0, 10 * 10);
	}

	bool isRotated90()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (after[j][len - i] != before[i][j])
					return false;
		}
		return true;
	}
	bool isRotated180()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (after[len - i][len - j] != before[i][j])
					return false;
		}
		return true;
	}
	bool isRotated270()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (after[len - j][i] != before[i][j])
					return false;
		}
		return true;
	}
	bool isReflected()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (after[i][len - j] != before[i][j])
					return false;
			}
		}
		return true;
	}
	bool isCombined()
	{
		SquarePattern temp;
		temp.n = n;
		temp.len = len;

		/* gets a mirror image */
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp.before[i][len - j] = before[i][j];
				temp.after[i][j] = after[i][j];
			}
		}
		if (temp.isRotated90()) return true;
		if (temp.isRotated180()) return true;
		if (temp.isRotated270()) return true;
		return false;
	}
	bool isNotChanged()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (after[i][j] != before[i][j])
					return false;
		}
		return true;
	}
	int getPattern()
	{
		if (isRotated90())	return 1;
		if (isRotated180()) return 2;
		if (isRotated270()) return 3;
		if (isReflected())	return 4;
		if (isCombined())	return 5;
		if (isNotChanged()) return 6;
		return 7;
	}
};

int main()
{
	ifstream in("transform.in");
	ofstream out("transform.out");
	SquarePattern p;
	
	/* gets data */
	in >> p.n;
	p.len = p.n - 1;

	int i, j;
	char temp;
	for (i = 0; i < p.n; i++)
	{
		for (j = 0; j < p.n; j++)
		{
			temp = in.get();
			p.before[i][j] =
				(char)((temp == '\n') ? in.get() : temp);
		}
	}
	for (i = 0; i < p.n; i++)
	{
		for (j = 0; j < p.n; j++)
		{
			temp = in.get();
			p.after[i][j] =
			(char)((temp == '\n') ? in.get() : temp);
		}
	}
	/* writes to file */
	// cout << p.getPattern();
	out << p.getPattern() << endl;

	/* closes files */
	in.close(), out.close();
	return 0;
}