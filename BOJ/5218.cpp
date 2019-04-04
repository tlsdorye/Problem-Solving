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
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		printf("Distances:");
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] <= b[i]) printf(" %d",b[i] - a[i]);
			else printf(" %d", b[i] + 26 - a[i]);
		}
		cout << endl;
	}
}
