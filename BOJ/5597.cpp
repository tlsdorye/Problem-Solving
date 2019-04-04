#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;

int main()
{
	int d[31] = { 0 };
	int t;
	for (int i = 0; i < 28; i++)
	{
		cin >> t;
		d[t]++;
	}
	for (int i = 1; i <= 30; i++)
		if (d[i] == 0) cout << i << "\n";
}