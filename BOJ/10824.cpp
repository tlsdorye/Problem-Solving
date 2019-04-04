#include<iostream>
#include<string.h>

using namespace std;

long long int result = 0;
char n[4][30];


long long int pow(int n)
{
	long long int x = 1;
	while (n--) x *= 10;
	return x;
}

void si(int p)
{
	int l = strlen(n[p]);
	for (int i = 0; i < l; i++)
		result += (n[p][i]-48)*pow(l-1-i);
	return;
}

int main()
{
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	strcat(n[0], n[1]);
	strcat(n[2], n[3]);
	si(0),si(2);
	printf("%lld\n", result);
	return 0;
}