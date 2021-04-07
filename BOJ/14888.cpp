#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> num;
vector<int> op(4, 0);

int max_ans = -2e9, min_ans = 2e9;

void Solve(int idx, int carry)
{
	if (idx >= N - 1)
	{
		max_ans = max(max_ans, carry);
		min_ans = min(min_ans, carry);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] <= 0) continue;
		op[i]--;
		int next_carry = carry;
		switch (i) 
		{
		case 0:
			next_carry += num[idx + 1];
			break;
		case 1:
			next_carry -= num[idx + 1];
			break;
		case 2:
			next_carry *= num[idx + 1];
			break;
		case 3:
			next_carry /= num[idx + 1];
			break;
		}
		Solve(idx + 1, next_carry);
		op[i]++;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;

	num.resize(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);

	Solve(0, num[0]);
	printf("%d\n%d", max_ans, min_ans);
}