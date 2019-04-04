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
	int d[10] = { 0 };
	int sum = 0, index = 9;
	for (int i = 0; i < 10; i++) cin >> d[i];
	for (int i = 0; i < 10; i++)
	{
		if (sum < 100) sum += d[i];
		else
		{
			index = i-1;
			break;
		}
	}
	if (-(sum - d[index] - 100) >= sum - 100) cout << sum;
	else cout << sum - d[index];
}