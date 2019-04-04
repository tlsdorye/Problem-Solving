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
	string s, tmp;
	cin >> s;
	int t = 0, ans = 0;
	for (int i = 0; i <= s.size(); i++)
		if (s[i] == ',' || i == s.size()) {
			tmp = s.substr(t, i - t);
			t = i + 1;
			ans += stoi(tmp);
		}
	cout << ans;
}