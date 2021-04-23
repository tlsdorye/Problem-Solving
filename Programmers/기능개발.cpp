#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> T;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<T> que;
    int size = progresses.size();
    for(int i=0;i<size;i++) {
        que.push({i, progresses[i], speeds[i]});
    }
    
    bool done[101] = {false};
    int start = -1, ans = 0;
    while(size > 0) {
        int idx, progress, speed;
        for(int i=0;i<size;i++) {
            tie(idx, progress, speed) = que.front();
            que.pop();
            progress += speed;
            if(progress >= 100) done[idx] = true;
            else que.push({idx, progress, speed});
        }
        while(done[start + 1]) {
            start++;
            ans++;
        }
        if(ans > 0) {
            answer.push_back(ans);
            ans = 0;
        }
        size = que.size();
    }
    
    return answer;
}