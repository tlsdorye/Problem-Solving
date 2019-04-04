#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int d[7] = { 0 };
	int s[7] = { 0 };
	int ans = 0;
	for (int i = 1; i <= 6; i++) cin >> d[i];

	ans += d[6] + d[5] + d[4] + d[3]/4;
	d[3] %= 4;
	if (d[3] != 0) s[3] = 36 - d[3] * 9, ans++;				// s[3] 남아있는거 활용 -> d[2] 로 활용해야함
	s[4] = d[4] * 20;										// s[4] 남아있는거 활용 -> d[2] 로 활용해야함
	s[5] = d[5] * 11;										// s[5] 남아있는거 활용 -> d[1] 로 활용해야함

	while (d[1] > 0 && s[5] > 0) d[1]--, s[5]--;			//d[1] 이 남았을 경우 존재
	while (d[2] > 0 && s[4] > 0) d[2]--, s[4] -= 4;			//d[2] 가 남았을 경우 존재
	while (d[1] > 0 && s[4] > 0) d[1]--, s[4]--;			//s[4]가 남았을 경우 d[1]을 쓴다  d[1]이 남았을 경우 존재

	int t = 0;
	if (d[3] == 1) t = 5;
	else if (d[3] == 2) t = 3;
	else if (d[3] == 3) t = 1;
	while (t > 0 && d[2] > 0) t--, d[2]--, s[3] -= 4;		// d[2] 가 남았을 경우 존재
	while (d[1] > 0 && s[3] > 0) d[1]--, s[3]--;

	ans += d[2] / 9;
	d[2] %= 9;
	if (d[2] != 0) s[2] = 36 - d[2] * 4, ans++;
	while (d[1] > 0 && s[2] > 0) d[1]--, s[2]--;

	ans += d[1] / 36;
	d[1] %= 36;
	if (d[1] != 0) ans++;
	cout << ans;
}