#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	if (s / n == 0) return { -1 };
	vector<int> answer;

	int mid = s / n;
	int rest = s % n;
	for (int i = 0; i < n; i++) {
		answer.push_back(mid);
		if (rest > 0) answer.back()++, rest--;
	}
	sort(answer.begin(), answer.end());

	return answer;
}