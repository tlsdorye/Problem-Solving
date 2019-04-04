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

int money[6] = { 500,100,50,10,5,1 };

int solve(int n,int i) {
	if (n == 0) return 0;
	else return  n / money[i] + solve(n%money[i], i+1);;
}

int main()
{
	int n;
	cin >> n;
	n = 1000 - n;
	cout << solve(n, 0);
}
