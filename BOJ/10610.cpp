#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;


int main()
{
	string s;
	cin >> s;

	bool zero = false;
	int sum = 0;
	vector<int> D;
	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i] - '0';
		sum += temp;
		D.push_back(temp);
		if (!zero && temp == 0) 
			zero = true;
	}
	if (!zero || (sum % 3 != 0))
	{
		printf("-1\n");
		return 0;
	}
	sort(D.begin(), D.end(), greater<int>());
	for (int i = 0; i < D.size(); i++)
		printf("%d", D[i]);
	return 0;
}