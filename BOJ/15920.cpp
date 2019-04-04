#include <iostream>
using namespace std;

int N;
char arr[11];
int section[11];
int ans = 0;

int main()
{
	cin >> N;

	int numW = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == 'W')
		{
			section[numW] = i;
			numW++;
		}
	}
	if (numW < 2)
	{
		printf("0");
		return 0;
	}

	bool flag = true;

	if (section[0] % 2 == 1) flag = false;
	if (section[1] - section[0] != 1) printf("6");
	else if(flag) printf("5");
	else if(!flag) printf("1");
	return 0;
}