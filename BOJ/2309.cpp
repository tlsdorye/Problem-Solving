#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d[9];
    int sum = 0;
    bool flag = false;
    for(int i=0;i<9;i++){
        cin >> d[i];
        sum += d[i];
        }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i != j && sum - d[i] - d[j] == 100){
                d[i] = -1;
                d[j] = -1;
                flag = true;
                break;
                }
            }
        if(flag) break;
        }
    sort(d,d+9);
    for(int i = 2;i<9;i++) cout << d[i] << endl;
    return 0;
}

    