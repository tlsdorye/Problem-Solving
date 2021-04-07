#include <iostream>
#include <vector>
using namespace std;

int N, M;

bool sel[9];
vector<int> nsel;

void Solve(int r) 
{
	if (r == 0)
	{
		for (auto x : nsel)
			printf("%d ", x);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (sel[i]) continue;
		sel[i] = true;
		nsel.push_back(i + 1);
		Solve(r - 1);
		nsel.pop_back();
		sel[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	Solve(M);

}
