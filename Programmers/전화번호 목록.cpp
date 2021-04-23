#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> num;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());
	for (string s : phone_book) {
		for (int i = 1; i <= s.size(); i++) {
			if (num.find(s.substr(0, i)) != num.end()) {
				answer = false;
				break;
			}
		}
		if (!answer) break;
		num.insert(s);
	}

	return answer;
}