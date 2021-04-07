#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

string a, b;

string concat(string s, int t) {
	string ret;
	while (t--) ret += s;
	return ret;
}

int main() {
	cin >> a >> b;

	string x = concat(a, b.size());
	string y = concat(b, a.size());

	int ANS = 0;
	if (x == y) ANS = 1;
	cout << ANS;
}