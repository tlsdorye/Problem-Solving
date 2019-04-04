#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef long long ll;

vector<int> d;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		d.push_back(t);
	}
	sort(d.begin(), d.end());
	cout << d.front()*d.back();
}