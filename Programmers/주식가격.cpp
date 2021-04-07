#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	stack<pair<int, int>> stk;

	for (int i = 0; i < prices.size(); i++)
	{
		if (stk.empty()) stk.push({ prices[i], i });
		else
		{
			while (!stk.empty() && stk.top().first > prices[i])
			{
				answer[stk.top().second] = i - stk.top().second;
				stk.pop();
			}
			stk.push({ prices[i], i });
		}
	}
	int last_idx = stk.top().second;
	while (!stk.empty())
	{
		answer[stk.top().second] = last_idx - stk.top().second;
		stk.pop();
	}

	return answer;
}