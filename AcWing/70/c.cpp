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
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dp[maxn];
int w[maxn];
int n,ans;
void dfs(int x,int fa,int c)
{
	dp[x]=w[x];
	ans=max(ans,dp[x]);
	int a=0,b=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		dfs(y,x,edge[i].w);
		dp[x]=max(dp[x],w[x]+dp[y]);
		ans=max(ans,dp[x]);
		b=max(b,dp[y]);
		if(b>a)swap(a,b);
	}
	ans=max(ans,a+b+w[x]);
	dp[x]-=c;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dfs(1,0,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}