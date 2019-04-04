#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#define MAX 200001
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;
		cout << 2 - v + e << endl;
	}
}