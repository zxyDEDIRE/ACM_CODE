#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bool vis[maxn];
int dis[maxn];
int in[maxn];
int n,ma,mb;

void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s)
{
	for(int i=0;i<=n;i++)
		dis[i]=INF,in[i]=vis[i]=0;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		in[x]++;
		if(in[x]>n+1)return 0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				if(!vis[y])q.push(y),vis[y]=1;
			}
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	for(int i=1;i<=mb;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(y,x,-w);
	}
	for(int i=1;i<n;i++)
		add(i+1,i,0);
	for(int i=1;i<=n;i++)
		add(0,i,0);
	if(!spfa(0)){  
		cout<<-1<<endl;
		return ;
	}
	spfa(1);
	cout<<(dis[n]==(INF)?-2:dis[n]);

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
