/*
ID: lhs14381
LANG: C++14
TASK: sort3
*/

#include <fstream>
#include <utility>
using namespace std;

static int swapcount;

void swapAndCount(int& lhs, int& rhs)
{
	swap(lhs, rhs);
	++swapcount;
}

/*
[srcbeg, srcend)의 src값으로
[dstbeg, dstend)의 first (없으면 second)값과 swap
*/
void func(int* v, int src, int srcbeg, int srcend, int first, int second, int dstbeg, int dstend)
{
	int i, j;
	int mem = dstbeg;

	for (i = srcbeg; i < srcend; i++)
	{
		if (v[i] == src)
		{
			for (j = mem; j < dstend; j++)
			{
				if (v[j] == first)
				{
					mem = j + 1;
					swapAndCount(v[i], v[j]);
					goto NEXT;
				}
			}
			if (j == dstend && mem < (dstend + 1))
			{
				for (j = dstbeg; j < dstend; j++)
				{
					if (v[j] == second)
					{
						swapAndCount(v[i], v[j]);
						goto NEXT;
					}
				}
			}
		}
	NEXT:
		;
	}
}

void sort3(int* v, int* nelem)
{
	func(v, 2, 0, nelem[0], 1, 3, nelem[0], nelem[1]);
	func(v, 2, nelem[1], nelem[2], 3, 1, nelem[0], nelem[1]);
	func(v, 3, 0, nelem[0], 1, 2, nelem[1], nelem[2]);
}

int main()
{
	ifstream in("sort3.in");
	ofstream out("sort3.out");

	/* gets data */
	int n;
	in >> n;

	int* arr = new int[n];
	int nelem[3] = { 0 };

	for (int i = 0; i < n; i++)
	{
		in >> arr[i];
		++nelem[arr[i] - 1];
	}
	nelem[1] += nelem[0];
	nelem[2] += nelem[1];

	/* algorithm */
	sort3(arr, nelem);

	/* prints */
	out << swapcount << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}