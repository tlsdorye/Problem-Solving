#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	double maxx = 0, sum = 0;
	cin >> t;
	vector<double> score(t, 0);
	for (int i = 0; i < t; i++)
	{
		cin >> score[i];
		if (maxx < score[i]) maxx = score[i];
	}
	for (int i = 0; i < t; i++)
		sum += score[i] / maxx * 100;
	printf("%.2lf", sum / t);
}