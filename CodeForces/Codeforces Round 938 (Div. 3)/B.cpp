#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=555;
int n,a,b;
void solve()
{
	cin>>n>>a>>b;
	map<int,int>mp;
	int mi=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			mi=min(mi,x);
			mp[x]++;
		}
	int pre=mi;
	mp[mi]--;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		{
			pre=pre+a;
			mp[pre]--;
		}
		int now=pre;
		for(int j=2;j<=n;j++)
		{
			now=now+b;
			mp[now]--;
		}
	}
	for(auto [x,y]:mp)
		if(y!=0){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
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
3 9 6
5 7 1
11 4 8

1 4 7
3 6 9
5 8 11
*/