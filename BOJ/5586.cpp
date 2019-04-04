#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <utility>
#include <string>
typedef long long ll;
using namespace std;

int main() {
	string a = "JOI", b = "IOI", s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i] == a[0] && s[i + 1] == a[1] && s[i + 2] == a[2]) x++;
		if (s[i] == b[0] && s[i + 1] == b[1] && s[i + 2] == b[2]) y++;
	}
	cout << x << endl << y;
}