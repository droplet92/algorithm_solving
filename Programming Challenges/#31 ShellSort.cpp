#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_TURTLES	200

bool isSame(int gaps[], int size)
{
	for (int i = 0; i < size; ++i) {
		if (gaps[i]) return false;
	}
	return true;
}

void BeTop(string s, vector<string> &v, int gaps[])
{
	int idx;
	auto target = find(v.begin(), v.end(), s);

	/* target�� idx ���ϱ� */
	for (idx = 0; idx < v.size(); ++idx)
		if (!v[idx].compare(*target)) break;

	/* v���� target�� ����� �� ���� ���� */
	v.erase(target);
	v.insert(v.begin(), s);
	cout << s << endl;

	/* gaps ��ġ �ٲٱ� */
	gaps[idx] = 0;
	for (int i = (v.size() - 1); i > 0; --i)
		gaps[i] = gaps[i - 1];
	gaps[0] = 0;
}

void Gap(int gaps[], vector<string> t, vector<string> s)
{
	int i, j;

	for (i = 0; i < t.size(); ++i)
	{
		/* s���� t�� ���� ã�� */
		for (j = 0; j < s.size(); ++j) {
			if (!t[i].compare(s[j])) break;
		}
		gaps[i] = i - j;
	}

	for (i = (t.size() - 2); i >= 0; --i)
	{
		for (j = (i + 1); j < t.size(); ++j)
			if (gaps[j] > 0) ++gaps[i];
	}
}

int main()
{
	vector<string> t;		/* �ź��� ���� */
	vector<string> s;		/* �ٲ��� �� ���� */
	string temp;			/* �ӽ� ���ڿ� */
	int gaps[MAX_TURTLES];	/* t�� s�� ���� ��ġ ���� */
	int k;					/* �׽�Ʈ ���̽� */
	int n;					/* �ź����� ���� */

	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> n;
		getchar();

		/* �ź��� ���� �Է� */
		for (int j = 0; j < n; ++j)
		{
			getline(cin, temp);
			t.push_back(temp);
		}
		
		/* �ٲ��� �� ���� �Է� */
		for (int j = 0; j < n; ++j)
		{
			getline(cin, temp);
			s.push_back(temp);
		}
		cout << endl;

		Gap(gaps, t, s);

		while(!isSame(gaps, n))
		{
			for (int j = (n - 1); j >= 0; --j)
			{
				if (gaps[j] > 0)
				{
					BeTop(t[j], t, gaps);
					break;
				}
			}
		}
		t.clear();
		s.clear();
		cout << endl;
	}
	return 0;
}

/*
2
3
Yertle
Duke of Earl
Sir Lancelot
Duke of Earl
Yertle
Sir Lancelot
9
Yertle
Duke of Earl
Sir Lancelot
Elizabeth Windsor
Michael Eisner
Richard M. Nixon
Mr. Rogers
Ford Perfect
Mack
Yertle
Richard M. Nixon
Sir Lancelot
Duke of Earl
Elizabeth Windsor
Michael Eisner
Mr. Rogers
Ford Perfect
Mack
*/