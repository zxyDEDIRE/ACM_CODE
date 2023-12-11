#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dfn[maxn],low[maxn],tot;
int stc[maxn],top,cnt;
vector<int>v[maxn];
bool vis[maxn];
bool Ge[maxn];
int col[maxn];
int n,s,t;
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	for(int y:v[x])
	{
		if(!vis[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=fa)Ge[x]=1;
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(v[x].size()>=2&&x==fa)Ge[x]=1;
}
void tar(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	stc[++top]=x;
	vis[x]=1;
	for(int y:v[x])
	{
		if(!vis[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++cnt;
		int y;
		do{
			y=stc[top--];
			vis[y]=0;
			col[x]=cnt;
		}while(x!=y);
	}
}
int main()
{
	cin>>n;
	while(1){
		int x,y;
		cin>>x>>y;
		if(x==0&&y==0)break;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,i);
		}
	}
	tot=0;
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tar(i,i);
	
}