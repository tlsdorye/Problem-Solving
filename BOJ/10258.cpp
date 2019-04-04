#include <iostream>
#include <string>
#include <vector>
typedef long long int ll;

using namespace std;

string s;
ll ans = 0;
bool flag = true;

ll ff(int n){
	ll e  = 1;
	for(int i=0;i<=n;i++) e*=2;
	return e;
}

void cutzero(){
	if(s=="") return;
	while(s[0]=='0'){
		s = s.substr(1,s.size());
		if(s=="") break;
	}
}

void solve(){
	cutzero();
	if(s=="") return ;
	else if(s=="1") {
		if(flag) ans+=1;
		else ans -= 1;
	}
	else{
		if(s[0]=='1',s[1]=='1'){
			s = s.substr(2,s.size());
			if(flag) ans += ff(s.size());
			else ans -= ff(s.size());
			solve();
		}
		else if(s[0]=='1',s[1]=='0'){
			s = s.substr(2,s.size());
			if(flag) ans += ff(s.size()+1) -1;
			else ans -= ff(s.size()+1)-1;
			flag = !flag;
			solve();
		}
	}
}

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> s;
		solve();
		cout << ans << endl;
		ans = 0;
		flag = true;
	}
	return 0;
}