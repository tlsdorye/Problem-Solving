#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;

bool grid[101][101];
vector<int> row, col;


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;

	row.push_back(0);
	col.push_back(0);

	int x, y;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &x, &y);
		if (x == 0) row.push_back(y);
		else if (x == 1) col.push_back(y);
	}
	row.push_back(M);
	col.push_back(N);
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());

	int ans = 0;
	for (int i = 1; i < row.size(); i++)
		for (int j = 1; j < col.size(); j++)
			ans = max(ans, (row[i] - row[i - 1])*(col[j] - col[j - 1]));
	cout << ans;

}