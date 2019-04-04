#include <iostream>
using namespace std;

int N, S, ans = 0;
int SET[21] = {0};

void subAdd(int idx,bool select, int sum)
{
	if(select) sum += SET[idx];
    if(idx == N-1)
    {
        if(sum == S) ans++;
        return;
    }
    subAdd(idx+1,true,sum);
	subAdd(idx+1,false,sum);
}

int main()
{
	cin >> N >> S;
    for(int i=0;i<N;i++) cin >> SET[i];
    subAdd(0,true,0);
    subAdd(0,false,0);
    if(S==0) ans--;
    cout << ans;
}