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
const int maxn=1e6+1000;
int dp[maxn],tot;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	tot=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>=dp[tot])dp[++tot]=p[i],ans=tot;
		else
		{
			int fl=lower_bound(dp+1,dp+1+tot,p[i])-dp;
			dp[fl]=p[i];
			ans=fl;
		}
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
/*
4
3 1 3 3 

6
1 3 2 7 4 7


6
3 1 1 3 3 2
1 1 3 2 3 3


1 1 2 3 3 3 
2 3 6 1 4 5 
*/