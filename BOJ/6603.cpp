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

int n;
vector<int> d;
void solve(vector<int> select, int start)
{
	vector<int> s(select);
	if (s.size() == 6)
	{
		for (int i = 0; i < 6; i++) cout << s[i] << " ";
		cout << "\n";
		return;
	}
	else
	{
		for (int i = start; 6 - s.size() <= n - i; i++)
		{
			s.push_back(d[i]);
			solve(s, i+1);
			s.pop_back();
		}
	}
}

int main()
{
	cin >> n;
	while (n != 0)
	{
		d.resize(n, 0);
		for (int i = 0; i < n; i++) cin >> d[i];
		vector<int> temp;
		solve(temp, 0);
		cout << "\n";
		d.clear();
		cin >> n;
	}
	return 0;
}