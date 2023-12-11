#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+7;
const ll INF=2147483647;
ll n,m;
ll s,t;
ll dis[maxn];
ll vis[maxn];
ll cnt,head[maxn];
struct Edge{
	ll to,next,w;
}edge[maxn];
struct node{
	ll id,dis;
	bool operator<(const node &a)const{return a.dis<dis;}
}top;
void add(int from,int to,ll w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	priority_queue<node>q;
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		top=q.top();q.pop();
		int now=top.id;
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[top.id];i;i=edge[i].next)
		{
			int j=edge[i].to;
			if(dis[now]+edge[i].w<dis[j])
			{
				dis[j]=dis[now]+edge[i].w;
				q.push(node{j,dis[j]});
			}
		}
	}
}
void solve()
{
	//cout<<2e31-1-2147483647;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)dis[i]=INF;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	dij(s);
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
}
signed main()
{
	freopen("C:\\Users\\tob\\Desktop\\in_2.txt","r",stdin);
	freopen("C:\\Users\\tob\\Desktop\\out_2.txt","w",stdout);
	clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
	fclose(stdin);
	fclose(stdout);
	return 0;
}