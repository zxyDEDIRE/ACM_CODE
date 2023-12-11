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
const int maxn=1e6+100;
struct Edge{	int to,next;}edge[maxn];
vector<int>v[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
bitset<maxn>bri;
stack<int>s;
int dep[maxn];
int _x,_y;
int n,m;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
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
		++tot;
		int y;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}

}
void dfs1(int x,int fa=0)
{
	dep[x]=dep[fa]+1;
	vis[x]=1;
	for(auto y:v[x])
		if(!vis[y])
			dfs1(y,x);
	if(dep[x]>dep[_x])_x=x;
}
void dfs2(int x,int fa=0)
{
	dep[x]=dep[fa]+1;
	vis[x]=1;
	for(auto y:v[x])
		if(!vis[y])
			dfs2(y,x);
	if(dep[x]>dep[_y])_y=x;

}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[x]!=col[y])
			{
				v[col[x]].push_back(col[y]);
				v[col[y]].push_back(col[x]);
			}
		}
	}
	dfs1(1);
	vis.reset();
	dfs2(_x);
	cout<<dep[_y]-1<<endl;
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
1 2
2 3
3 1
3 4
*/