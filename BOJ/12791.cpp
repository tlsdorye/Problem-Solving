#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cmath>
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	vector<pair<int, string>> v;
	v.push_back(make_pair(1967,"DavidBowie"));
	v.push_back(make_pair(1969,"SpaceOddity"));
	v.push_back(make_pair(1970,"TheManWhoSoldTheWorld"));
	v.push_back(make_pair(1971,"HunkyDory"));
	v.push_back(make_pair(1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
	v.push_back(make_pair(1973,"AladdinSane"));
	v.push_back(make_pair(1973,"PinUps"));
	v.push_back(make_pair(1974,"DiamondDogs"));
	v.push_back(make_pair(1975,"YoungAmericans"));
	v.push_back(make_pair(1976,"StationToStation"));
	v.push_back(make_pair(1977,"Low"));
	v.push_back(make_pair(1977,"Heroes"));
	v.push_back(make_pair(1979,"Lodger"));
	v.push_back(make_pair(1980,"ScaryMonstersAndSuperCreeps"));
	v.push_back(make_pair(1983,"LetsDance"));
	v.push_back(make_pair(1984,"Tonight"));
	v.push_back(make_pair(1987,"NeverLetMeDown")); 
	v.push_back(make_pair(1993,"BlackTieWhiteNoise"));
	v.push_back(make_pair(1995,"1.Outside"));
	v.push_back(make_pair(1997,"Earthling"));
	v.push_back(make_pair(1999,"Hours"));
	v.push_back(make_pair(2002,"Heathen"));
	v.push_back(make_pair(2003,"Reality"));
	v.push_back(make_pair(2013,"TheNextDay"));
	v.push_back(make_pair(2016,"BlackStar"));
	int t;
	cin >> t;
	int S, E;
	while (t--)
	{
		cin >> S >> E;
		int ans = 0;
		vector<pair<int, string>> A;
		for (int i = 0; i < v.size(); i++)
			if (S <= v[i].first && v[i].first <= E) ans++, A.push_back(v[i]);
		cout << ans << endl;
		for (int i = 0; i < A.size(); i++) cout << A[i].first << " " << A[i].second << endl;
	}
}