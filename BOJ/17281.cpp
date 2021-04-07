#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <utility>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, ans;
int inning[51][10];
bool base[4];
vector<int> player = { 2, 3, 4, 5, 6, 7, 8, 9 };

int ret[10];
bool sel[10];

void getScore()
{
	int score = 0;

	player.insert(player.begin() + 3, 1);
	int idx = 0;

	for (int i = 1; i <= N; i++)
	{
		memset(base, false, sizeof(base));
		int out = 0;
		while (out < 3)
		{
			int cur = player[idx++];
			base[0] = true;
			int move = inning[i][cur];
			if (move == 0) out++;
			else
			{
				for (int i = 3; i >= 0; i--)
				{
					if (base[i] == 0) continue;
					if (move + i >= 4) score++;
					else base[move + i] = true;
					base[i] = false;
				}
			}
			idx %= 9;
		}
	}
	ans = max(ans, score);
	player.erase(player.begin() + 3);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			scanf("%d", &inning[i][j]);

	do getScore();
	while (next_permutation(player.begin(), player.end()));
	printf("%d\n", ans);
}