#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, double> P;

bool cmp(P &x, P &y)
{
	if (x.second > y.second) return true;
	else if (x.second < y.second) return false;
	else if (x.second == y.second) return x.first < y.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<P> fail(N + 1, { 0, 0 });
	for (int i = 0; i < stages.size(); i++)
		fail[stages[i] - 1].second++;

	double total = stages.size();
	for (int i = 0; i <= N; i++)
	{
		fail[i].first = i + 1;
		double temp = fail[i].second;
		fail[i].second /= total;
		total -= temp;
	}

	sort(fail.begin(), fail.end() - 1, cmp);

	for (int i = 0; i < N; i++) answer.push_back(fail[i].first);

	return answer;
}