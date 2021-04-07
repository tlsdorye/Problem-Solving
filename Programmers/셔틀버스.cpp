#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int get_int_time(string s) {
	return 1000 * (s[0] - '0') +
		100 * (s[1] - '0') +
		10 * (s[3] - '0') +
		(s[4] - '0');
}

string get_string_time(int i) {
	string s = to_string(i);
	while (s.size() <= 3) s = "0" + s;
	return s.substr(0, 2) + ":" + s.substr(2, 2);
}

int carculate_time(int a, int b) {
	int ret = a / 100 * 100;
	int minute = a % 100 + b;
	if (minute >= 60) ret = ret + 100 + (minute - 60);
	else if (minute < 0) ret = ret - 100 + (60 + minute);
	else ret += minute;
	if (ret >= 2400) ret -= 2400;
	return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	deque<int> time_table;
	for (string s : timetable) time_table.push_back(get_int_time(s));
	sort(time_table.begin(), time_table.end());
	int cur = 900;
	for (int i = 1; i <= n; i++) {
		int pass = 0;
		if (i == n) {
			while (!time_table.empty() &&
				pass < time_table.size() && 
				time_table[pass] <= cur &&
				pass < m) pass++;
			if (pass < m) answer = get_string_time(cur);
			else answer = get_string_time(carculate_time(time_table[pass - 1], -1));
			break;
		}
		else {
			while (!time_table.empty() &&
				time_table[0] <= cur &&
				pass < m) {
				time_table.pop_front();
				pass++;
			}
		}
		cur = carculate_time(cur, t);
	}
	return answer;
}

int main() {
	int n = 1, t = 1, m = 5;
	vector<string> timetable = {
		"00:01", "00:01", "00:01", "00:01", "00:01"
	};

	cout << solution(n, t, m, timetable);
}