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
ll p[maxn];
ll n;
void solve()
{
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],ans+=p[i];
	sort(p+1,p+1+n);
	// ll res=0;
	// for(int i=1;i<=n;i++)
	// {
	// 	if(i==1)
	// 	{
	// 		ll mi=min(p[1]+1,p[2]);
	// 		ll ma=max(p[1]+1,p[n]);
	// 		res=max(res,ans+1-mi-ma);
	// 	}
	// 	else if(i==n)
	// 	{
	// 		ll mi=min(p[n]+1,p[1]);
	// 		ll ma=p[n]+1;
	// 		res=max(res,ans+1-mi-ma);
	// 	}
	// 	else
	// 	{
	// 		ll mi=min(p[1],p[i]);
	// 		ll ma=max(p[n],p[i]+1);
	// 		res=max(res,ans+1-mi-ma);
	// 	}
	// }
	// cout<<res<<endl;


	if(p[1]==p[n])cout<<ans-p[1]-p[n]<<endl;
	else if(p[n]==p[1]+1&&p[2]!=p[1])cout<<ans-p[1]-p[n]<<endl;
	else cout<<ans-p[1]-p[n]+1<<endl;
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
4
1 1 2 2
*/