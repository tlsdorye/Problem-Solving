#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
typedef pair<int, int> P;

deque<int> wheels[4];

P move(int idx, int cw)
{
	P ret = { wheels[idx][6], wheels[idx][2] };
	if (cw == 1)
	{
		wheels[idx].push_front(wheels[idx].back());
		wheels[idx].pop_back();
	}
	else
	{
		wheels[idx].push_back(wheels[idx].front());
		wheels[idx].pop_front();
	}
	return ret;
}

void solve(int idx, int cw)
{
	idx--;
	P info = move(idx, cw);
	int left = info.first, rot = cw;
	for (int i = idx + 1; i < 4; i++)
	{
		if (info.second != wheels[i][6]) rot = -rot, info = move(i, rot);
		else break;
	}
	info.first = left, rot = cw;
	for (int i = idx - 1; i >= 0; i--)
	{
		if (info.first != wheels[i][2]) rot = -rot, info = move(i, rot);
		else break;
	}
		
}

int main()
{
	int x;
	for (int i = 0; i < 32; i++)
	{
		scanf("%1d", &x);
		wheels[i / 8].push_back(x);
	}
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		solve(a, b);
	}
	int sum = 0;
	if (wheels[0][0] == 1) sum += 1;
	if (wheels[1][0] == 1) sum += 2;
	if (wheels[2][0] == 1) sum += 4;
	if (wheels[3][0] == 1) sum += 8;
	cout << sum;
}