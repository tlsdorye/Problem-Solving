#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int N;
int board[21][21];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int shark_size = 2;
int eat_fish_num = 0;
P shark_pos;
vector<tuple<int, int, int>> _fish_info;
list<tuple<int, int, int>> fish_info;

int ans = 0;


bool Check(int x, int y)
{
	if (x < 1 || x > N || y < 1 || y > N) return false;
	if (board[x][y] > shark_size) return false;
	return true;
}

int GetShortestDistance(P start, P end)
{
	int ret = 0;
	queue<P> que;
	bool isvisit[21][21] = { false };

	que.push(start);
	isvisit[start.first][start.second] = true;
	while (!que.empty())
	{
		int qsize = que.size();
		for (int i = 0; i < qsize; i++)
		{
			P curr = que.front();
			que.pop();
			if (curr == end) return ret;
			for (int j = 0; j < 4; j++)
			{
				int next_x = curr.first + dx[j], next_y = curr.second + dy[j];
				if (isvisit[next_x][next_y] || !Check(next_x, next_y)) continue;
				que.push({ next_x, next_y });
				isvisit[next_x][next_y] = true;
			}
		}
		ret++;
	}
	return -1;
}

bool IsSharkEatFish()
{
	int mindistance = 10000;
	auto erase_pos = fish_info.end();
	for (auto it = fish_info.begin(); it != fish_info.end(); it++)
	{
		if (shark_size <= get<0>(*it)) break;
		int temp = GetShortestDistance(shark_pos, { get<1>(*it), get<2>(*it) });
		if (temp < 0) continue;
		if (mindistance > temp) mindistance = temp, erase_pos = it;
		else if (mindistance == temp)
		{
			P p1 = { get<1>(*erase_pos), get<2>(*erase_pos) };
			P p2 = { get<1>(*it), get<2>(*it) };
			if (p2 < p1) mindistance = temp, erase_pos = it;
		}
	}

	if (erase_pos == fish_info.end()) return false;
	ans += mindistance;
	if (++eat_fish_num == shark_size)
	{
		shark_size++;
		eat_fish_num = 0;
	}
	shark_pos = { get<1>(*erase_pos), get<2>(*erase_pos) };
	//printf("size: %d, pos: [%d, %d], eat_num: %d, ans: %d\n", shark_size, shark_pos.first - 1, shark_pos.second - 1, eat_fish_num, ans);
	fish_info.erase(erase_pos);
	return true;
}

void Solve()
{
	while (!fish_info.empty())
		if (!IsSharkEatFish()) break;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == 9) shark_pos = make_pair(i, j), board[i][j] = 0;
			if (1 <= board[i][j] && board[i][j] <= 6) _fish_info.push_back(make_tuple(board[i][j], i, j));
		}
	sort(_fish_info.begin(), _fish_info.end());
	fish_info.assign(_fish_info.begin(), _fish_info.end());
	//printf("size: %d, pos: [%d, %d], eat_num: %d, ans: %d\n", shark_size, shark_pos.first - 1, shark_pos.second - 1, eat_fish_num, ans);
	Solve();
	cout << ans;
}