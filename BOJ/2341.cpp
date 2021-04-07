#include <iostream>
#include <string>
#include <cmath>
// code 개수
#define NUM_CODE 4
#define MAX_N 50
using namespace std;

// 입력 변수 N, W
int N, W;
// 입력 수열[최대길이 N + 1]
int seq[MAX_N + 1];
// 변환비용를 담는 배열
// n번째 수까지 선택하고, m번째 코드로 변환했을 때의 변환비용 저장
int change_cost[MAX_N + 1][NUM_CODE];
// 변환코드를 담는 배열
// n번째 수까지 선택하고, m번째 코드로 변환했을 때의 변환코드 저장
string change_code[MAX_N + 1][NUM_CODE];
// 변환 레벨
int level[NUM_CODE] = { 1, 86, 172, 256 };
// 코드 배열
string code[NUM_CODE] = { "00", "01", "10", "11" };


int main()
{
	// 입력 시작
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> seq[i];
	// 입력 끝

	// 알고리즘 시작
	// 최소값을 구하기 위해서 변환비용 배열을 맥스값(나올 수 없는 최대값)으로 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			change_cost[i][j] = 987654321;

	// 동적계획법을 사용하기 위해서 0번째 열 초기화
	// 0번째 수가 변환될 code[i]을 선택했을 때
	for (int i = 0; i < 4; i++)
	{
		// 변환코드 저장
		change_code[0][i] = code[i];
		// 변환비용 저장
		change_cost[0][i] = abs(seq[0] - level[i]);
		change_cost[0][i] += change_code[0][i].length() * W;
	}

	// 1번째 수부터 N-1번째 수 까지 가면서 아래의 코드를 반복한다
	for (int i = 1; i < N; i++)
	{
		// 0번째 code부터 마지막 code코드까지 한번씩 변환 해볼건데
		for (int j = 0; j < NUM_CODE; j++)
		{
			// 각각을 변환할 때 이전까지 저장했던 값들을 보고 판단할거임
			for (int k = 0; k < NUM_CODE; k++)
			{
				// 다음 저장할 변환코드
				string next_code = change_code[i - 1][k];
				// 이전 코드와 같으면 0추가
				if (j == k) next_code += "0";
				// 다르면 1 + 해당코드 추가
				else next_code += "1" + code[j];
				// 다음 저장할 변환비용
				int next_cost = change_cost[i - 1][k] + abs(seq[i] - level[j]);
				// 바뀐 변환코드 길이만큼 추가
				next_cost += (next_code.length() - change_code[i - 1][k].length()) * W;
				// i, j에 해당하는 변환비용값이 현재 구한 next_cost보다 작으면 값을 유지할 필요 없음
				if (change_cost[i][j] <= next_cost) continue;
				// 그렇지 않다면 해당 값들을 저장함
				change_code[i][j] = next_code;
				change_cost[i][j] = next_cost;
			}
		}
	}
	// 알고리즘 끝

	// 출력준비
	int min_cost = 987654321;
	int min_idx = -1;
	for (int i = 0; i < 4; i++)
	{
		if (min_cost > change_cost[N - 1][i])
		{
			min_cost = change_cost[N - 1][i];
			min_idx = i;
		}
	}
	cout << min_cost << "\n";
	cout << change_code[N - 1][min_idx];
	//출력끝
}