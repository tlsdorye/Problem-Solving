#include<iostream>

using namespace std;
int main()
{
	int n, count = 2;
	char before, after;
	cin >> n;
	cin >> before;

	for (int i = 1; i < n; i++) {
		cin >> after;
		if (after != before)count++;
		before = after;
	}
	cout << count;
}