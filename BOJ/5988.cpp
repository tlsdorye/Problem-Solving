#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll N;
string S;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		if ((S[S.size() - 1]-'0') % 2 == 0)
			printf("even\n");
		else printf("odd\n");
	}
}