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

	/* target의 idx 구하기 */
	for (idx = 0; idx < v.size(); ++idx)
		if (!v[idx].compare(*target)) break;

	/* v에서 target을 지우고 맨 위에 삽입 */
	v.erase(target);
	v.insert(v.begin(), s);
	cout << s << endl;

	/* gaps 위치 바꾸기 */
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
		/* s에서 t의 원소 찾기 */
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
	vector<string> t;		/* 거북이 스택 */
	vector<string> s;		/* 바뀌어야 할 스택 */
	string temp;			/* 임시 문자열 */
	int gaps[MAX_TURTLES];	/* t와 s의 원소 위치 차이 */
	int k;					/* 테스트 케이스 */
	int n;					/* 거북이의 개수 */

	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> n;
		getchar();

		/* 거북이 스택 입력 */
		for (int j = 0; j < n; ++j)
		{
			getline(cin, temp);
			t.push_back(temp);
		}
		
		/* 바뀌어야 할 스택 입력 */
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