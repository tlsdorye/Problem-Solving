#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;
void makeMap(vector<string>& queries);


map<pair<string, int>, int> forwards, backwards;
vector<tuple<string, int, int>> index;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	makeMap(queries);
	for (string word : words)
	{
		int word_size = word.size();
		for (int i = 1; i <= word_size; i++)
		{
			string comp1 = word.substr(0, i);
			auto it1 = forwards.find({ comp1, word_size });
			if (it1 != forwards.end()) it1->second++;

			string comp2 = word.substr(i, word_size);
			auto it2 = backwards.find({ comp2, word_size });
			if (it2 != backwards.end()) it2->second++;
		}
	}
	for (tuple<string, int, int> p : index)
	{
		if (get<2>(p) == 0) answer.push_back(forwards[{get<0>(p), get<1>(p)}]);
		else answer.push_back(backwards[{get<0>(p), get<1>(p)}]);
	}
	return answer;
}

void makeMap(vector<string>& queries)
{
	for (string s : queries)
	{
		int idx = 0;
		string key_str;
		if (s[0] == '?')
		{
			while (s[idx] == '?') idx++;
			key_str = s.substr(idx, s.size());
			backwards.insert({ {key_str, s.size()}, 0 });
			index.push_back({ key_str, s.size(), 1 });
		}
		else
		{
			while (s[idx] != '?') idx++;
			key_str = s.substr(0, idx);
			forwards.insert({ {key_str, s.size()}, 0 });
			index.push_back({ key_str, s.size(), 0 });
		}
	}
}



int main()
{
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	solution(words, queries);
}