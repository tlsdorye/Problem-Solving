#include <iostream>
using namespace std;

int N;
float average = 0, expo = 0;
float D[101] = { 0 };
int value[101] = { 0 };

int main()
{
	cin >> N;
	if (N == 0)
	{
		printf("divide by zero");
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
		D[value[i]]++;
		average += value[i];
	}

	average /= N;
	for (int i = 1; i <= 100; i++)
		if (D[i] != 0) expo += i * (D[i] / N);

	if(expo < 1e-3) printf("divide by zero");
	else
	{
		float ans = average / expo;
		printf("%.2f", ans);
	}
	return 0;
}