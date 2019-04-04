#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int d[1001][16][16];
vector<P> player;

bool bdc(int k, int x, int y)
{
	return 1 <= k && k < 1001 && 0 <= x && x < 16 && 0 <= y && y < 16;
}

int solve(int k, int x, int y)
{
	if (!bdc(k, x, y)) return 0;
	if (d[k][x][y] != -1) return d[k][x][y];
	if (k < x + y) return d[k][x][y] = 0;
	if (x == 0 && y == 0) return d[k][x][y] = 0;
	if (x == 0) return d[k][x][y] = max(solve(k - 1, x, y), solve(k - 1, x, y - 1) + player[k].second);
	if (y == 0) return d[k][x][y] = max(solve(k - 1, x, y), solve(k - 1, x - 1, y) + player[k].first);
	int ret = max(solve(k - 1, x, y), max(solve(k - 1, x - 1, y) + player[k].first, solve(k - 1, x, y - 1) + player[k].second));
	return d[k][x][y] = ret;
}

int main()
{
	memset(d, -1, sizeof(d));
	int x, y;
	player.push_back(make_pair(0, 0));
	while (cin >> x >> y) player.push_back(make_pair(x, y));
	d[1][1][0] = player[1].first;
	d[1][0][1] = player[1].second;
	cout << solve(player.size()-1, 15, 15);
}