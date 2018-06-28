#include <iostream>
#include <string>
using namespace std;

#define MAXKEY 13

void GoLeft(string s) {
	string numbers = "`1234567890-=";	// 13
	string qwerty = "QWERTYUIOP[]\\";	// 13
	string asdf = "ASDFGHJKL;'";		// 11
	string zxc = "ZXCVBNM,./";			// 10

	for (int i = 0; i < s.length(); ++i) {
		for (int j = 1; j < MAXKEY; ++j) {
			if (s[i] == numbers[j]) s[i] = numbers[j - 1];
			else if (s[i] == qwerty[j]) s[i] = qwerty[j - 1];
			else if (j < 11 && s[i] == asdf[j]) s[i] = asdf[j - 1];
			else if (j < 10 && s[i] == zxc[j]) s[i] = zxc[j - 1];
		}
	}
	cout << s << endl;
}

int main() {
	string text;

	while (1) {
		getline(cin, text, '\n');

		if (!text.length()) break;
		GoLeft(text);
	}
	return 0;
}