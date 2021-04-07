#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, answer = 9;
void rotate_weak(deque<int> &weak, int pivot);
void solve(int depth, deque<int> weak, vector<int> &dist);

int solution(int n, vector<int> _weak, vector<int> dist) {
	N = n;
	sort(dist.begin(), dist.end());
	if (N <= dist[dist.size() - 1]) return 1;

	deque<int> weak(_weak.begin(), _weak.end());
	int pivot = weak[0];

	for (int w : weak) {
		rotate_weak(weak, pivot);
		pivot = weak[1] - weak[0];

		do {
			vector<int> copy(dist);
			solve(0, weak, copy);
		} while (next_permutation(dist.begin(), dist.end()));

		int front = weak[0];
		weak.pop_front();
		weak.push_back(front);
	}

	if (answer == 9) return -1;
	return answer;
}

void rotate_weak(deque<int> &weak, int pivot) {
	for (int i = 0; i < weak.size(); i++)
		weak[i] = (weak[i] + N - pivot) % N;
}

void solve(int depth, deque<int> weak, vector<int> &dist) {
	if (weak.size() == 0) {
		answer = min(answer, depth);
		return;
	}
	if (dist.size() <= 0) return;

	int cur = dist[dist.size() - 1];
	dist.pop_back();

	deque<int> cw;
	for (int i = 0; i < weak.size(); i++)
		if (weak[i] > cur) cw.push_back(weak[i]);
	if (cw.size() > 0) rotate_weak(cw, cw[0]);
	solve(depth + 1, cw, dist);

}