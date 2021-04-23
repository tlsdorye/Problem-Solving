#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int x : scoville) que.push(x);
    while(!que.empty()) {
        int first = que.top();
        que.pop();
        
        if(first >= K) break;
        
        int second = -1;
        if(!que.empty()) {
            second = que.top();
            que.pop();
        }
        if(second == -1) {
            answer = -1;
            break;
        }
        que.push(first + 2 * second);
        answer++;
    }
    return answer;
}