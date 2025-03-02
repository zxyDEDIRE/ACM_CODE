#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=400;
int head[maxn],cnt;
int dis[maxn];
int vis[maxn];
int n;
struct Edge{
	int to,next,w;
}edge[maxn];
struct node{
	int id,val;
	bool operator<(const node a)const{return a.val<val;}
	node(int a,int b){id=a,val=b;}
};
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	q.push(node(s,0));
	dis[s]=0;
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		cout<<"X:"<<x<<endl;
		if(vis[x]||x!=s)continue;
		vis[x]++;
		if(x==s&&vis[x]==2)
		{
			cout<<dis[x]<<endl;
			return ;
		}
		
		cout<<dis[x]<<endl;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			cout<<""<<" "<<y<<endl;
			if(dis[y]>dis[x]+edge[i].w)
			{
				cout<<"*";
				dis[y]=dis[x]+edge[i].w;
				q.push(node(y,dis[y]));
			}
		}
		if(x==s&&vis[x]==1)dis[x]=INF;
	}
	cout<<"ans:";
	cout<<-1<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1,x;j<=n;j++)
		{
			cin>>x;
			if(x>0){
				cout<<i<<" "<<j<<" "<<x<<endl;
				add(i,j,x);
			}
		}
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
		dij(i);
}