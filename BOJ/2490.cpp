#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#include <functional>
#define MAX 987654321
typedef long long ll;
using namespace std;

int main()
{
	int t = 3;
	while (t--)
	{
		int d, ans = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> d;
			if (d == 0) ans++;
		}
		if (ans == 0) cout << "E" << endl;
		else if (ans == 1) cout << "A" << endl;
		else if (ans == 2) cout << "B" << endl;
		else if (ans == 3) cout << "C" << endl;
		else if (ans == 4) cout << "D" << endl;
	}
}