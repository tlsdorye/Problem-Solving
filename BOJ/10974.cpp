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

void solve(vector<int> select, vector<bool> nonselect)
{
	vector<int> s(select);
	vector<bool> ns(nonselect);
	if (s.size() == n)
	{
		for (int i = 0; i < n; i++) cout << s[i] + 1 << " ";
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!ns[i])
			{
				s.push_back(i);
				ns[i] = true;
				solve(s, ns);
				s.pop_back();
				ns[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	vector<int> d;
	vector<bool> visit(n, false);
	solve(d, visit);
}