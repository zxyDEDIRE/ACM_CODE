/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pii pre[1<<22];
int dp[1<<22];
int p[40];
int n,m;
void dfs(int s)
{
	auto [x,y]=pre[s];
	if(y)dfs(y);
	cout<<x<<" ";
}
void solve()
{
	cin>>n>>m;
	if(m==((1+n-1)*(n-1)/2)){
		cout<<0<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		p[i]|=(1ll<<(i-1));
	for(int i=1;i<(1<<n);i++)
		dp[i]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[x]|=(1<<(y-1));
		p[y]|=(1<<(x-1));
		dp[p[x]]=1;pre[p[x]]={x,0};
		dp[p[y]]=1;pre[p[y]]={y,0};
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))&&dp[i|p[j]]>(dp[i]+1))
			{
				dp[i|p[j]]=dp[i]+1;
				pre[i|p[j]]={j,i};
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	dfs((1<<n)-1);
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}