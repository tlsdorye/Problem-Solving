#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#define MAX 987654321
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> d(n);
		for (int i = 0; i < n; i++)	cin >> d[i], d[i]--;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp = i, next;
			while(d[tmp] != -1)
			{
				next = d[tmp];
				d[tmp] = -1;
				tmp = next;
				if (d[tmp] == -1) ans++;
			}
		}
		cout << ans << endl;
	}
}