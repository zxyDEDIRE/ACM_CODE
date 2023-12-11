#pragma GCC optimize(2)
#pragma GCC optimize(3,"inline")
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=2e6+10;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
int dep[maxn],f[maxn];
int fa[maxn];
bool vis[maxn];
stack<int>s;
int n,m,ans;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init(){
	for(int i=1;i<=n;i++){
		head[i]=dfn[i]=low[i]=0;
	}
	cnt=1;
}
void tarjan(int x,int F)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==F)continue;
		if(!dfn[y])
		{
			fa[y]=x;
			dep[y]=dep[x]+1;
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y]){
				f[y]=1;ans++;
			}
		}
		else if(vis[y]&&dfn[y]<dfn[x])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
		}while(x!=y);
	}
}
void solve()
{
	int T=0;
	while(cin>>n>>m&&(n!=0&&m!=0)){
		cout<<"Case "<<++T<<":\n";
		init();
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			add(x,y,0);
			add(y,x,0);
		}
		tarjan(1,0);
		int q;cin>>q;
		while(q--) 
		{
			int x,y;cin>>x>>y;
			while(x!=y){
				if(dep[x]<dep[y])swap(x,y);
				if(f[x])ans--,f[x]=0;
				x=fa[x];
			}
			cout<<ans<<"\n";
		}
		cout<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
