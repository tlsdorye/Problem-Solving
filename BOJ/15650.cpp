#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> nsel;

void Solve(int idx, int r) 
{
	if (r == 0)
	{
		for (auto x : nsel)
			printf("%d ", x);
		printf("\n");
		return;
	}
	for (int i = idx; i <= N; i++)
	{
		nsel.push_back(i);
		Solve(i + 1, r - 1);
		nsel.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	Solve(1, M);

}
