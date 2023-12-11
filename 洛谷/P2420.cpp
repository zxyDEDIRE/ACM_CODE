/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
ll dis[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		dis[y]=dis[x]^edge[i].w;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dfs(1,1);

	cin>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		cout<<(dis[x]^dis[y])<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}