#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_K = 11;

bool changeNum[MAX_K][MAX_N+1];

int getLength(int n)
{
	int ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return ret;
}

int getIndex(int n,int idx)
{
	for (int i = 1; i < idx; i++) n /= 10;
	return n % 10;
}

int change(int n, int idx, int jdx)
{
	int ret = n;
	int ith = 1, jth = 1;
	for (int i = 1; i < idx; i++) ith *= 10;
	for (int i = 1; i < jdx; i++) jth *= 10;
	ret -= getIndex(n, idx)*ith;
	ret -= getIndex(n, jdx)*jth;
	ret += getIndex(n, idx)*jth;
	ret += getIndex(n, jdx)*ith;
	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;
	changeNum[0][N] = true;
	for (int k = 1; k <= K; k++)
	{
		for (int n = 1; n <= MAX_N; n++)
		{
			if (changeNum[k-1][n] == false) continue;
			int currLen = getLength(n);
			for (int i = 1; i <= currLen; i++)
				for (int j = i + 1; j <= currLen; j++) 
				{
					if (j == currLen && getIndex(n, i) == 0) continue;
					changeNum[k][change(n, i, j)] = true;
				}
		}
	}
	bool flag = false;
	for (int i = MAX_N; i > 0; i--)
	{
		if (changeNum[K][i] == true)
		{
			cout << i << endl;
			flag = true;
			break;
		}
	}
	if (!flag) cout << "-1" << endl;
	return 0;
}