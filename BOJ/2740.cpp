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
	int A[100][100] = { 0 };
	int B[100][100] = { 0 };
	int C[100][100] = { 0 };
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> B[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
		{
			for (int x = 0; x < m; x++)
				C[i][j] += A[i][x] * B[x][j];
			cout << C[i][j] << " ";
		}
		cout << endl;
}