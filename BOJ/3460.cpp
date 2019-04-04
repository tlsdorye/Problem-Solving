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

string s = "";

void solve(int n) 
{
	if (n == 0) return;
	else
	{
		s += (n % 2 + '0');
		solve(n / 2);
	}
}

int main()
{
	int n,t;
	cin >> t;
	while (t--)
	{
		s = "";
		cin >> n;
		solve(n);
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '1') cout << i << " ";
		cout << endl;
	}
}
