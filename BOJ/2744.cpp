#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (islower(s[i])) s[i] = toupper(s[i]);
		else s[i] = tolower(s[i]);
	}
	cout << s;
}
