#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;

	int ANS = 0;
	bool flag = false;
	while (S.size() < T.size()) {
		if (T.back() == 'A') T.pop_back();
		else if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		else {
			flag = true;
			break;
		}
	}
	if (!flag && S == T) ANS = 1;
	cout << ANS;
}