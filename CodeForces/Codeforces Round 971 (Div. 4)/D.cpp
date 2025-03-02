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
void solve()
{
	int n;
	map<int,int>mp;

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x]|=(1<<y);
	}
	vector<pii>v;
	for(auto &[x,y]:mp)
		v.push_back({x,y});

	ll ans=0;
	int len=v.size();

	for(int i=0;i<len;i++)
	{
		auto &[x,y]=v[i];
		if(y==3)ans+=n-2;
		if(i>0&&i<len-1)
		{
			if(x-v[i-1].first!=1)continue;
			if(v[i+1].first-x!=1)continue;
			if((y&1)&&(v[i-1].second&2)&&(v[i+1].second&2))ans++;
			if((y&2)&&(v[i-1].second&1)&&(v[i+1].second&1))ans++;
		}
	}
	cout<<ans<<endl;
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