#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int A, B, C, D;
int P, M, N;
int time;
int nP, nM, nN;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> A >> B >> C >> D;
	cin >> P >> M >> N;

	time = 0;
	
	int pa = P % (A + B);
	int pb = P % (C + D);
	int ma = M % (A + B);
	int mb = M % (C + D);
	int na = N % (A + B);
	int nb = N % (C + D);
	if (0 < pa && pa <= A) nP++;
	if (0 < pb && pb <= C) nP++;
	if (0 < ma && ma <= A) nM++;
	if (0 < mb && mb <= C) nM++;
	if (0 < na && na <= A) nN++;
	if (0 < nb && nb <= C) nN++;
	printf("%d\n%d\n%d", nP, nM, nN);
}