#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int f(int l,int r,int x) { // l <= x <= r
    int cnt = 0;
    while(l <= r) {
        cnt++;
        int mid = (l + r) / 2;
        if (mid == x) break;
        if (mid < x) l = mid + 1;
        else r = mid - 1;
    }
    return cnt;
}
void solve()
{
	int l,r,cnt;
	cin>>l>>r>>cnt;
	map<int,int>mp;
	for(int i=l;i<=r;i++){
		cout<<i<<" "<<f(l,r,i)<<endl;
		int x=f(l,r,i);
		mp[x]++;
	}
	cout<<endl;
	for(auto [x,y]:mp)
		cout<<x<<" "<<y<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
6 7 8 9 10 11 12
3 2 3 1 3  2  3
*/