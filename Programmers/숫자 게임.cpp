#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	deque<int> a(A.begin(), A.end()), b(B.begin(), B.end());

	while (!a.empty())
	{
		if (a.front() > b.front())
		{
			a.pop_back();
			b.pop_front();
		}
		else if (a.front() < b.front())
		{
			a.pop_front();
			b.pop_front();
			answer++;
		}
		else
		{
			if (a.back() < b.back())
			{
				b.pop_back();
				a.pop_back();
				answer++;
			}
			else if (a.back() > b.back())
			{
				a.pop_back();
				b.pop_front();
			}
			else
			{
				a.pop_back();
				b.pop_front();
			}
		}
	}
	return answer;
}