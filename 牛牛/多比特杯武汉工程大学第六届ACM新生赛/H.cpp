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
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string str;cin>>str;
		p[i]=(str=="byl");
	}
	if(k==1)
	{
		ll ans=1ll*n*(n+1)/2;
		for(int i=1;i<=n;i++)
			if(!p[i])ans--;
		cout<<ans<<endl;
		return ;
	}
	ll ans=1ll*n*(n+1)/2;
	int cnt=0;
	for(int i=1,r=1;i<=n;i++)
	{
		while(r<=n&&cnt<k)
			cnt+=p[r],r++;
		// cout<<i<<" "<<r<<" ";
		if(cnt==k)ans-=((r-1)-i+1-1);
		else ans-=(r-i);



		cnt-=p[i];
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
5 1
acm byl bcm byl byl
*/