#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int D[65][65];
int N;

void solve(P s, P v)
{
	bool isZ = false, isO = false;
	
	for (int i = s.first; i <= v.first; i++)
		for (int j = s.second; j <= v.second; j++)
		{
			if (D[i][j] == 0) isZ = true;
			else if (D[i][j] == 1) isO = true;
		}
	if (isZ && isO)
	{
		cout << "(";
		solve(s, make_pair((s.first + v.first - 1) / 2, (s.second + v.second - 1) / 2));
		solve(make_pair(s.first, (s.second + v.second + 1) / 2), make_pair((s.first + v.first - 1) / 2, v.second));
		solve(make_pair((s.first + v.first + 1) / 2, s.second), make_pair(v.first, (s.second + v.second - 1) / 2));
		solve(make_pair((s.first + v.first + 1) / 2, (s.second + v.second + 1) / 2), v);
		cout << ")";
	}
	else if (isZ) cout << "0";
	else if (isO) cout << "1";
	
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) scanf("%1d", &D[i][j]);

	solve(make_pair(1, 1), make_pair(N, N));
	return 0;
}
