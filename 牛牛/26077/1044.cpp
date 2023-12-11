#include<bits/stdc++.h>
#define int long long
#define die {puts("-1");exit(0);}
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
int in[maxn];
int n,m;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa()
{
	bitset<maxn>vis;
	for(int i=1;i<=n;i++)dis[i]=-INF;
	dis[0]=0;
	vis[0]=1;
	in[0]=1;
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		if(in[x]>=n)die
		in[x]++;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]<dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				if(!vis[y]){
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	return 1;
}
signed main()
{
	read(n);read(m);
	while(m--)
	{
		int fl,x,y;
		read(fl);read(x);read(y);
		if(fl==1)
		{
			add(x,y,0);
			add(y,x,0);
		}
		else if(fl==2)
		{
			if(x==y)die;
			add(x,y,1);
		}
		else if(fl==3)
		{
			add(y,x,0);
		}
		else if(fl==4)
		{
			if(x==y)die;
			add(y,x,1);
		}
		else if(fl==5)
		{
			add(x,y,0);
		}
	}
	for(int i=n;i>=1;i--)
		add(0,i,1);
	int t=spfa();
	if(!t)cout<<-1<<endl;
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=dis[i];
		cout<<ans<<endl;
	}
}