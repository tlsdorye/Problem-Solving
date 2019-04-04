#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int l, c;
vector<char> d;
char vowel[5] = { 'a','e','i','o','u' };

bool check(vector<bool> visit)
{
	int a = 0, b;
	for (int i = 0; i < c; i++)
		if (visit[i])
			for (int j = 0; j < 5; j++)
				if (d[i] == vowel[j])
				{
					a++;
					break;
				}
	b = l - a;
	return a >= 1 && b >= 2;
}

void solve(vector<bool> visit, int draw, int curr)
{
	if (draw == l)
	{
		if (check(visit))
		{
			for (int i = 0; i < c; i++)
				if (visit[i]) cout << d[i];
			cout << "\n";
		}
		return;
	}
	else
	{
		for (int i = curr; l - draw <= c - i; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				solve(visit, draw + 1, i);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	cin >> l >> c;
	d.resize(c, '1');
	for (int i = 0; i < c; i++)
		cin >> d[i];
	sort(d.begin(), d.end());
	vector<bool> v(c, false);
	solve(v, 0, 0);
}