/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int maxn=3e3+100;
struct P{int x,y;}p[maxn];
vector<int>v[maxn];
vector<int>G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int dp[maxn];
int in[maxn];
stack<int>s;
int n,d,c;
void init()
{
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		v[i].clear();
		dfn[i]=0;
		num[i]=0;
		dp[i]=0;
		in[i]=0;
	}
	while(s.size())s.pop();
	vis.reset();
	indx=0;
	tot=0;
}
bool ok(int _x,int _y)
{
	auto a=p[_x];
	auto b=p[_y];
	ll h=1ll*a.y+d-b.y;
	ll w=1ll*abs(a.x-b.x);
	return w<=h;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
			num[tot]++;
		}while(x!=y);
	}
}
void dfs(int x)
{
	vis[x]=1;
	for(auto y:G[x])
		if(!vis[y])
			dfs(y);
}
void solve()
{
	cin>>n>>d>>c;
	init();
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(ok(i,j))
				v[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]);
	for(int x=1;x<=tot;x++)
	{
		sort(G[x].begin(),G[x].end());
		G[x].erase(unique(G[x].begin(),G[x].end()),G[x].end());
	}
	vis.reset();
	dfs(col[c]);

	for(int x=1;x<=tot;x++)
	{
		v[x].clear();
		if(!vis[x])continue;
		for(auto y:G[x])
			if(vis[y]){
				v[x].push_back(y);
				in[y]++;
			}
		G[x].clear();
	}
	queue<int>q;

	for(int i=1;i<=tot;i++)
		if(in[i]==0&&vis[i]){
			q.push(i);
		}
	vis.reset();
	vis[col[c]]=1;
	while(!q.empty())
	{ 
		int x=q.front();q.pop();
			dp[x]+=num[x];
		for(auto y:v[x])
		{
				dp[y]=max(dp[y],dp[x]);//,vis[y]=1;
			in[y]--;
			if(!in[y])
			{
				q.push(y);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __,_;cin>>__>>_;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 0
4 2 1
2 4
1 1
5 2
4 1

1 0
2 0 1
0 2
0 0

1 0
4 2 1
1 1
4 1
1 4
4 4
*/