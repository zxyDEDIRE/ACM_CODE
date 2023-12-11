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
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
vector<pii>v[maxn];
int dfn[maxn],low[maxn],indx;
bitset<maxn>vis;
int cut[maxn];
stack<int>s;
int n,m,flag;
void init()
{
	for(int i=1;i<=n;i++)
		v[i].clear(),cut[i]=dfn[i]=low[i]=head[i]=0;
	while(s.size())s.pop();
	vis.reset();
	flag=0;
	indx=0;
	cnt=1;
}
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
			if(low[y]>=dfn[x])
			{
				cut[x]=1;
				int v;
				do{
					v=s.top();s.pop();
				}while(v!=y);
			}
		}
		else if(vis[y]&&dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x)
{
	vis[x]=1;
	for(auto &[y,w]:v[x])
	{
		if(cut[y]&&vis[y])w=1;
		if(vis[y])continue;
		dfs(y);
	}
}
void dfs1(int x)
{
	if(flag)return ;
	if(vis[x]==1){
		flag=1;
		return ;
	}
	vis[x]=1;
	for(auto [y,w]:v[x])
	{
		if(w==1)continue;
		dfs1(y);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)continue;
		add(x,y);
		add(y,x);
		v[x].push_back({y,0});
	}
	vis.reset();
	tarjan(1,0);
	cut[1]=1;
	dfs(1);
	vis.reset();
	dfs1(1);
	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<cut[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
4 4
1 2
1 3
3 4
4 3
*/