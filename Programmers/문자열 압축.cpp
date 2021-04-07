#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1개 이상의 단위로 자르기
// 문자열의 길이: L이면 L/2만큼 확인해보면 됨

int solution(string s)
{
	int answer = s.size();
	int step = 0, size = s.size();
	while (++step <= size / 2)
	{
		int temp_ans = 0, cnt = 1;
		string unit = s.substr(0, step);
		for (int i = step; i < size; i += step)
		{
			string comp = s.substr(i, step);
			//cout << unit + " " + comp + " ";
			if (unit == comp) cnt++;
			else
			{
				temp_ans += step;
				if (cnt > 1) temp_ans += to_string(cnt).size();
				unit = comp;
				cnt = 1;
			}
			//cout << cnt << " " << temp_ans << "\n";
		}
		if (size % step == 0)
		{
			temp_ans += unit.size();
			if (cnt > 1) temp_ans += to_string(cnt).size();
		}
		else temp_ans += (size % step);
		answer = min(answer, temp_ans);
		//cout << answer << "\n";
	}
	return answer;
}