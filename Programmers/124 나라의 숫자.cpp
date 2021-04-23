#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
typedef long long ll;

char digit[4] = { '0', '1', '2', '4' };
vector<ll> unit;

void initUnit() {
	unit.clear();
	ll value = 1;
	while (value <= 500000000) {
		unit.push_back(value);
		value *= 3;
	}
}

string solution(int n) {
	string answer = "";
	initUnit();
	int start = unit.size() - 1;
	while (unit[start] > n) start--;

	for (start; start >= 0; start--) {
		int x = n / unit[start];
		n = n % unit[start];
		answer += to_string(x);
	}

	int size = answer.size() - 1;
	int temp = 0;
	for (int i = size; i >= 0; i--) {
		int cur = answer[i] - '0';
		if (cur + temp > 0) {
			answer[i] = digit[cur + temp];
			temp = 0;
		}
		else {
			answer[i] = digit[3 + cur + temp ];
			temp = -1;
		}
		if (temp < 0 && i == 0) answer = answer.substr(1);
	}

	return answer;
}