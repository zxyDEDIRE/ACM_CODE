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
map<int,int>mp;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<pii>p;
	for(int i=1;i<=n;i++){ 
		int x;cin>>x;
		mp[x]++;
	}
	for(auto [x,y]:mp)
		p.push_back({x,y});

	int cnt=0,ans=0;
	for(int i=0,r=0;i<p.size();i++)
	{
		while(r<p.size()&&p[r].first<p[i].first+m)
			cnt+=p[r].second,r++;
		ans=max(ans,cnt);
		cnt-=p[i].second;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}