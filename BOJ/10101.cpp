#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int A[3];

int main()
{
	cin >> A[0] >> A[1] >> A[2];
	if (A[0] == 60 && A[1] == 60 && A[2] == 60) cout << "Equilateral";
	else if (A[0]+A[1]+A[2] == 180)
	{
		if (A[0] == A[1] || A[1] == A[2] || A[2] == A[0]) cout << "Isosceles";
		else cout << "Scalene";
	}
	else cout << "Error";
}
