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
const int N=2e5+10;
int dp[N][266];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=256;j++)
			dp[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=256;j++)
		{
			dp[i][j]=min(dp[i][j], dp[i-1][j]);
			if(dp[i-1][j]==INF)continue;
			int x=(j&p[i]);
			dp[i][x]=min(dp[i][x],dp[i-1][j]+1);
		}
		dp[i][p[i]]=min(dp[i][p[i]],1);
	}
	if(dp[n][0]==INF)cout<<-1<<endl;
	else cout<<n-dp[n][0]<<endl;
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
https://www.hm08.lol//download-index-aid-243725.html
*/