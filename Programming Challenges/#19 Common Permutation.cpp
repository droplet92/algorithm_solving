#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXLEN 1000
#define ALPHABET 24

int main() {
	string s1, s2;
	string shortest, longest;
	vector<char> common;

	while (true) {
		//두 문장 입력
		getline(cin, s1);

		if (s1.empty()) break;	//입력 없으면 종료
		getline(cin, s2);

		shortest = s1.length() < s2.length() ? s1 : s2;
		longest = s2 == shortest ? s1 : s2;

		//긴 문장에서 짧은 문장의 단어들 검색
		for (int i = 0; i < shortest.length(); ++i) {
			if (longest.find(shortest[i]) != longest.npos) {
				common.push_back(shortest[i]);
			}
		}
		//정렬하여 출력
		sort(common.begin(), common.end());
		for (auto& i : common) {
			cout << i;
		}
		cout << '\n';

		common.clear();
	}
	return 0;
}

/*
pretty
women
walking
down
the
street
*/