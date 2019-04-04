#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll T, x, y;

int main()
{
    cin >> T;
    for(int t=0;t<T;t++)
    {
        cin >> x >> y;
        ll s = sqrt(y-x);
        if(s*(s+1) >= y-x) s -=1;
        ll ans = s*2;
        ll n = y-x-s*(s+1);
        if(n <= s+1) ans++;
        else if( n > s+1) ans+=2;
        cout << ans << endl;
    }
}