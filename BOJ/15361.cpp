#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, ans = 20, temp = 0;

int D[101][16];
int choice[16];
int visit[16];

int getOne()
{
	int ret = 0;
	int d[16] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (choice[D[i][j]] == 1) continue;
			d[D[i][j]]++;
			break;
		}
	for (int i = 1; i <= M; i++)
		if (d[ret] < d[i]) ret = i;
	for (int i = 1; i <= M; i++)
		if (ret != i && d[ret] == d[i]) ret = min(ret, i);

	return ret;
}

void solve(int d)
{
	if (d == K) solve(d + 1);
	if (d == M + 1) return;
	choice[d] = 1;
	temp++;
	if (getOne() == K) ans = min(temp, ans);
	solve(d + 1);
	choice[d] = 0;
	temp--;
	solve(d + 1);
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> D[i][j];

	int first = getOne();
	cout << first << endl;

	if(first != K) solve(1);
	else ans = 0;

	cout << ans;
}