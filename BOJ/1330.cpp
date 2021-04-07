#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> P;



int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b) cout << ">";
	else if (a < b) cout << "<";
	else cout << "==";
}