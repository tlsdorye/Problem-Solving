#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
#include <vector>
#include <utility>

using namespace std;

vector<string> solution(vector<string> record) 
{
	vector<string> answer;
	vector < pair<string, int>> timeline;
	map<string, string> user_id;
	string enter = "님이 들어왔습니다.", leave = "님이 나갔습니다.";
	for (string s : record)
	{
		istringstream iss(s);
		vector<string> token{ istream_iterator<string>{iss}, istream_iterator<string>{} };
		if (token[0] == "Enter")
		{
			user_id[token[1]] = token[2];
			timeline.push_back({ token[1], 0 });
		}
		else if (token[0] == "Leave") timeline.push_back({ token[1], 1 });
		else if (token[0] == "Change") user_id[token[1]] = token[2];
	}
	for (int i = 0; i < timeline.size(); i++)
	{
		string result = user_id[timeline[i].first];
		if (timeline[i].second == 0) result += enter;
		else result += leave;
		answer.push_back(result);
	}
	return answer;
}