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
struct node{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dp[maxn][3];
int a[maxn];
int n,ma;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int fa)
{
	dp[x][0]=dp[x][1]=a[x];
	int m_a=0,m_b=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(y==fa)continue;
		dfs(y,x);
		dp[x][0]=max(dp[x][0],dp[y][0]+a[x]-w);
		m_b=max(m_b,dp[y][0]-w);
		if(m_b>m_a)swap(m_a,m_b);
	}
	dp[x][1]+=m_a+m_b;
	ma=max({ma,dp[x][1],dp[x][0],a[x]});
	// cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<" "<<a[x]<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dfs(1,0);
	cout<<ma<<endl;
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