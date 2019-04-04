#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N, ans = 1;
vector<P> conf;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		conf.push_back(make_pair(y, x));
	}
	sort(conf.begin(), conf.end());

	int prev = 0;
	for (int i = 1; i < N; i++)
		if (conf[prev].first <= conf[i].second)
		{
			ans++;
			prev = i;
		}

	cout << ans;
	return 0;
}
