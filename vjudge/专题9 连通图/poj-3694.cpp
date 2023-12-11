#include<iostream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<vector>
using namespace std;
const int maxn=1e6+10;
struct Edge{
	int to,next,w;
}edge[maxn];
vector<int>v[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int dep[maxn];
int fa[maxn];
int f[maxn];
int n,m,ans;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init(){
	for(int i=1;i<=n;i++){
		head[i]=dfn[i]=low[i]=dep[i]=0;
		v[i].clear();
	}
	while(!s.empty())s.pop();
	vis.reset();
	indx=tot=ans=0;
	cnt=1;
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
			if(dfn[x]<low[y])ans++;
		}
		if(i!=(fa^1)&&vis[y]&&dfn[y]<dfn[x])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;col[y]=tot;
		}while(x!=y);
	}
}

int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void dfs(int x,int F)
{
	fa[x]=F;
	dep[x]=dep[F]+1;
	for(int i=0;i<(int)v[x].size();i++){
		int y=v[x][i];
		if(y!=F)
			dfs(y,x);
	}
}
void solve()
{
	// cin>>n>>m;
	int T=0;
	while(cin>>n>>m&&(n!=0&&m!=0)){

	cout<<"Case "<<++T<<":\n";
	init();
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y,0);
		add(y,x,0);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(1,0);
	for(int x=1;x<=n;x++)
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(col[x]!=col[y])
				v[col[x]].push_back(col[y]);
		}
	// for(int i=1;i<=tot;i++){
	// 	if(v[i].size()==0)continue;
	// 	sort(v[i].begin(),v[i].end());
	// 	v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
	// }
	dfs(1,0);
	ans=tot-1;
	for(int i=1;i<=tot;i++)
		f[i]=1;
	int q;cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x=col[x];
		y=col[y];
		while(x!=y)
		{  
			if(dep[x]<dep[y])swap(x,y);
			if(f[x])f[x]=0,ans--;
			x=fa[x];
		}
		cout<<ans<<"\n";
	}
	cout<<"\n";

	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
