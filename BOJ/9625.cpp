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
	int a = 1, b = 0, tmp, n;
	cin >> n;
	while (n--)
	{
		tmp = a;
		a = b;
		b = tmp + b;
	}
	cout << a << " " << b;
}