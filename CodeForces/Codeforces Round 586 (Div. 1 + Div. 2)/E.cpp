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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],cnt=1;
int low[maxn],dfn[maxn],indx;
vector<int>v[maxn];
int col[maxn],tot;
bitset<maxn>vis;
int bri[maxn];
int num[maxn];
stack<int>s;
int dp[maxn];
int f[maxn];
int _p[maxn];
int p[maxn];
int n,m,S,ans;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
				bri[i]=bri[i^1]=1;
		}
		else if(vis[y]&&dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		tot++;
		int y;
		do{
			num[tot]++;
			y=s.top();s.pop();
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void dfs(int x,int sum)
{
	ans=max(ans,sum);
	for(auto y:v[x])
	{
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,sum+_p[y]);
		vis[y]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	cin>>S;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=tot;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=edge[j].next)
		{
			int fa=find(col[i]);
			int fb=find(col[j]);
			if(fa!=fb&&num[fa]>1&&num[fb]>1)
			{
				f[fb]=fa;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		col[i]=find(col[i]);
		_p[col[i]]+=p[i];
	}
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[x]!=col[y])
				v[col[x]].push_back(col[y]);
		}
	}
	S=col[S];
	vis.reset();
	vis[S]=1;
	dfs(S,_p[S]);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4 4
4 4 4 4 
1 2
2 3
3 1
1 4
*/