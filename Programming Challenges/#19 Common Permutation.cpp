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
		//�� ���� �Է�
		getline(cin, s1);

		if (s1.empty()) break;	//�Է� ������ ����
		getline(cin, s2);

		shortest = s1.length() < s2.length() ? s1 : s2;
		longest = s2 == shortest ? s1 : s2;

		//�� ���忡�� ª�� ������ �ܾ�� �˻�
		for (int i = 0; i < shortest.length(); ++i) {
			if (longest.find(shortest[i]) != longest.npos) {
				common.push_back(shortest[i]);
			}
		}
		//�����Ͽ� ���
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