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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1e3+10;
ll dp[N][N];
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;k=n-k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		dp[i][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int t=1;t<k;t++)
			{
				if(p[i]%p[j]==0)
				{
					dp[i][t+1]+=dp[j][t];
					dp[i][t+1]%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=k;i<=n;i++)
		ans+=dp[i][k],ans%=mod;
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
/*
1 4 2 3 6 7
*/ 