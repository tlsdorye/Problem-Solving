#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int cnt[10], MAX, ans = 1;

int solution(vector<int> priorities, int location)
{
	queue<P> que;
	for (int i = 0; i < priorities.size(); i++)
	{
		que.push({ i, priorities[i] });
		cnt[priorities[i]]++;
		MAX = max(MAX, priorities[i]);
	}

	while (!que.empty())
	{
		P cur = que.front();
		que.pop();
		if (cur.second < MAX) que.push(cur);
		else if (cur.second == MAX)
		{
			cnt[MAX]--;
			if (cur.first == location) return ans;
			while (cnt[MAX] == 0) MAX--;
			ans++;
		}
	}
}