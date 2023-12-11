/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
#define endl "\n"
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*t);
	memset(last+1,-1,sizeof(int)*t);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
int MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t]; 
		}
	}
	return maxc;
}
void solve()
{
	while(cin>>n>>m&&n)
	{
		vector<pair<int,int> >a,b;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char ch;cin>>ch;
				if(ch=='m')a.push_back(pair<int,int>(i,j));
				if(ch=='H')b.push_back(pair<int,int>(i,j));
			}
		}
		n=a.size();
		s=n*2+1;
		t=n*2+3;
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int c=abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second);
				add(i+1,j+1+n,1,c);
				add(j+1+n,i+1,0,-c);
			}
		}
		for(int i=1;i<=n;i++)
		{
			add(s,i,1,0);
			add(i,s,0,0);
		}
		for(int i=n+1;i<=n*2;i++)
		{
			add(i,t,1,0);
			add(t,i,0,0);
		}
		cout<<MCMF(s,t)<<endl;
	}
	
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}