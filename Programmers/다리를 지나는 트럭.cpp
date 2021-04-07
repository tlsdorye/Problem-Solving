#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int curr_time = 0, truck_idx = 0, curr_weight_sum = 0;
	int truck_num = truck_weights.size();

	queue<pair<int, int>> que;

	while (truck_idx < truck_num)
	{
		if (que.empty())
		{
			curr_weight_sum += truck_weights[truck_idx];
			que.push({ truck_weights[truck_idx++], ++curr_time });
		}
		else
		{
			if (curr_time == bridge_length + que.front().second - 1)
			{
				curr_weight_sum -= que.front().first;
				que.pop();
			}

			if (curr_weight_sum + truck_weights[truck_idx] <= weight)
			{
				curr_weight_sum += truck_weights[truck_idx];
				que.push({ truck_weights[truck_idx++], ++curr_time });
			}
			else curr_time = bridge_length + que.front().second - 1;
		}
	}
	while (!que.empty())
	{
		curr_time = bridge_length + que.front().second;
		que.pop();
	}


	return curr_time;
}

int main()
{
	vector<int> tr = { 7, 4, 5, 6 };
	cout << solution(2, 10, tr);
}