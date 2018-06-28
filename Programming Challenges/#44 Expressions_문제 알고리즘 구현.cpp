#include <iostream>
#include <string>
#include <algorithm>	//max함수
using namespace std;

bool isCorrect(string e) {
	if (e[0] == ')') return false;
	int climb = 0;
	char before = NULL;

	for (auto& ch : e) {
		if (ch == before) {
			if (ch == '(') ++climb;
			else if (!climb) return false;	//climb은 항상 0이상
			else --climb;
		}
		before = ch;
	}
	if (climb) return false;	//climb이 0이면 양 괄호의 개수가 같음
	return true;
}

void Divide(string e, string& lhs, string& rhs) {
	if (e.empty()) return;
	if (!isCorrect(e)) return;
	int climb = 0;

	for (int i = 1; i < e.length(); ++i) {
		if ((e[i] != e[i - 1]) && !climb) {
			lhs = e.substr(0, i);
			rhs = e.substr(i, e.length() - i);
			return;
		}
		if (e[i] == e[i - 1]) {
			if (e[i] == '(') ++climb;
			else --climb;
		}
	}
}

int Depth(string e) {
	string a;
	string lhs, rhs;
	
	if (isCorrect(e) && !e.empty()) {
		a = e.substr(1, e.length() - 2);
	}
	Divide(e, lhs, rhs);

	if (!e.length()) return 0;
	if (isCorrect(a) && !a.empty()) return Depth(a) + 1;
	if ((isCorrect(lhs) && !lhs.empty()) && (isCorrect(rhs) && !rhs.empty()))
		return max(Depth(lhs), Depth(rhs));
}

int main() {
	string text;	/* 입력 */

	while (getline(cin, text)) {
		cout << Depth(text) << endl;
	}
	return 0;
}