#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
	int answer = 0;
	int cookie_size = cookie.size();

	vector<int> sum(cookie_size + 1, 0);
	for (int i = 0; i < cookie_size; i++)
		sum[i + 1] = sum[i] + cookie[i];

	for (int m = 1; m < cookie_size; m++)
	{
		int prev = sum[m];
		for (int r = m + 1; r <= cookie_size; r++)
		{
			int next = sum[r] - prev;
			if (prev < next || next <= answer) continue;
			for (int l = 0; l < m; l++)
				if (next == prev - sum[l]) {
					answer = next;
					break;
				}
		}
	}
	return answer;
}