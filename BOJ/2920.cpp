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
	int d[9] = { 0 };
	bool ascending = true, descending = true;
	for (int i = 1; i <= 8; i++)
	{
		cin >> d[i];
		if (ascending && d[i] != i) ascending = false;
		if (descending && d[i] != 9 - i) descending = false;
	}
	if (ascending) cout << "ascending";
	else if (descending) cout << "descending";
	else cout << "mixed";
}