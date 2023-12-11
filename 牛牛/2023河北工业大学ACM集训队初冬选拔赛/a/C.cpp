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
ll a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int cnt=0;
	map<pii,int>mp;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])cnt++;
		if(a[i]!=b[i])
			mp[{a[i],b[i]}]++;
	}
	ll ans=n;

	if(cnt>1)
	{
		cnt--;
		ans+=1ll*(1+cnt)*cnt;
	}
	cout<<ans<<endl;
	for(auto [x,t]:mp)
	{
		if(t>1)
		{
			t--;
			ans+=1ll*(1+t)*t;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
2 1 +1
3 3 +2
4   +3
*/