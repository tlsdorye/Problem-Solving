#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int N;

int main()
{
	cin >> N;
	vector<P> v;
	int last = 0;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		P p = make_pair(x, y);
		if (i == 0) v.push_back(p);
		else
		{
			last = v.size() - 1;
			if (v[last].second >= p.first && v[last].second <= p.second) v[last].second = p.second;
			else if (v[last].second >= p.first && v[last].second > p.second) continue;
			else if (v[last].second < p.first) v.push_back(p);
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		ans = ans + (v[i].second - v[i].first);

	cout << ans;

}