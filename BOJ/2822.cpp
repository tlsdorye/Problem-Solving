#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;

int main()
{
	priority_queue<P> que;
	priority_queue<int, vector<int>, greater<int>> q;
	int s;
	for (int i = 1; i <= 8; i++)
	{
		cin >> s;
		que.push(make_pair(s,i));
	}
	int ans = 0;
	while (que.size() > 3)
	{
		P p = que.top();
		ans += p.first;
		q.push(p.second);
		que.pop();
	}
	cout << ans << "\n";
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
}