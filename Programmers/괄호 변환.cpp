#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef pair<string, string> P;
pair<string, string> getBalancedParan(string w);
bool validParan(string w);

string solution(string p) {
	// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
	if (p.empty()) return p;
	string answer = "";

	// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
	P strs = getBalancedParan(p);
	string u = strs.first;
	string v = strs.second;

	// 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
	// 3 - 1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
	if (validParan(u))
		answer =  u + solution(v);
	// 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
	else
	{
		// 4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
		string new_str = "(";

		// 4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
		new_str += solution(v);

		// 4 - 3. ')'를 다시 붙입니다.
		new_str += ")";

		// 4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
		for (int i = 1; i < u.size() - 1; i++)
		{
			if (u[i] == '(') new_str += ')';
			else new_str += '(';
		}

		// 4 - 5. 생성된 문자열을 반환합니다.
		answer = new_str;
	}
	return answer;
}

pair<string, string> getBalancedParan(string w)
{
	// u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
	string u = "", v = "";
	int open = 0, close = 0;
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i] == '(') open++;
		else close++;
		if (open == close) return { w.substr(0, i + 1), w.substr(i + 1, w.size()) };
	}
}

bool validParan(string w)
{
	stack<char> stk;
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i] == '(') stk.push(w[i]);
		else
		{
			if (stk.empty()) return false;
			if (stk.top() == '(') stk.pop();
		}
	}
	return true;
}