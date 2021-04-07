#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;

	int xdx;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &xdx);
		arr.push_back(xdx);
	}
	for (int i = arr.size() - 2; i >= 0; i--) {
		if (arr[i] > arr[i + 1]) {
			xdx = i;
			break;
		}
	}
	int ydx = -1, max = -1;
	for (int i = xdx; i < N; i++) {
		if (arr[xdx] > arr[i] && arr[i] > max) {
			max = arr[i];
			ydx = i;
		}
	}
	if (ydx == -1) {
		cout << -1;
		return 0;
	}
	swap(arr[xdx], arr[ydx]);
	for (int i = 0; i <= xdx; i++)
		printf("%d ", arr[i]);
	for (int i = N - 1; i > xdx; i--)
		printf("%d ", arr[i]);

}