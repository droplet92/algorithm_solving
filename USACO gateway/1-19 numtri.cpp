/*
ID: lhs14381
LANG: C++14
TASK: numtri
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	node *left, *right;
	int sumleft, sumright;
	int num;

	node(int n) :
		left(nullptr),
		right(nullptr),
		sumleft(n),
		sumright(n),
		num(n)
	{}
};

static vector<vector<node>> triangle;

int main()
{
	ifstream in("numtri.in");
	ofstream out("numtri.out");
	int r, temp;
	node* parent;

	/* gets data */
	in >> r;

	/* algorithm */
	for (int i = 0; i < r; i++)
	{
		vector<node> row;

		for (int j = 0; j <= i; j++)
		{
			in >> temp;
			node newnode(temp);
			if (i > 0)
			{
				if (j < i)
				{
					parent = &triangle[i - 1][j];
					parent->left = &newnode;
					newnode.sumright += max(parent->sumleft, parent->sumright);
				}
				if (j > 0)
				{
					parent = &triangle[i - 1][j - 1];
					parent->right = &newnode;
					newnode.sumleft += max(parent->sumleft, parent->sumright);
				}
			}
			row.push_back(newnode);
		}
		triangle.push_back(row);
	}
	int maxval = 0;
	for (auto& n : triangle[r - 1])
	{
		temp = max(n.sumleft, n.sumright);
		maxval = max(maxval, temp);
	}

	/* prints */
	out << maxval << endl;

	/* closes */
	in.close(), out.close();
	return 0;
}