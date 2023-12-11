#include<iostream>
#include<algorithm>
#include<bitset>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=444;
#define pii pair<int,int>
struct node{
	int id;double dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(){}
	node(int a,double b):id(a),dis(b){}
};
struct Edge{
	int to,next;double w;
}edge[maxn];
int head[maxn],cnt;
map<pii,int>mp;
pii p[N][N];
bitset<N>vis;
double dis[N];
int num[N];
pii s,t;
int n,m,tot;
void add(int from,int to,double w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
double f(pii &a,pii &b,double v){
	return sqrt(v*(a.first-b.first)*(a.first-b.first)+v*(a.second-b.second)*(a.second-b.second))/v;
}
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();dis[s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push(node(y,dis[y]));
			}
		}
	}
}
void solve()
{
	cin>>s.first>>s.second>>t.first>>t.second;
	mp[s]=++tot;
	mp[t]=++tot;
	add(1,2,f(s,t,10));
	n=0;
	int j=0;
	while(cin>>p[++n][0].first>>p[n][0].second)
	{
		j=0;
		while(cin>>p[n][++j].first>>p[n][j].second&&(p[n][j].first!=-1&&p[n][j].second!=-1));
		num[n]=j-1;
	}
	n--;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<num[i]<<endl;
		if(!mp.count(p[i][0]))mp[p[i][0]]=++tot;
		add(mp[s],mp[p[i][0]],f(s,p[i][0],10));
		add(mp[p[i][0]],mp[t],f(p[i][0],t,10));
		for(int j=1;j<=num[i];j++)
		{
			if(!mp.count(p[i][j]))mp[p[i][j]]=++tot;
			add(mp[p[i][j]],mp[p[i][j-1]],f(p[i][j],p[i][j-1],40));
			add(mp[p[i][j-1]],mp[p[i][j]],f(p[i][j],p[i][j-1],40));
			add(mp[s],mp[p[i][j]],f(s,p[i][j],10));
			add(mp[p[i][j]],mp[t],f(p[i][j],t,10));
		}
	}
	dij(1);
	for(int i=1;i<=tot;i++)
		cout<<dis[i]<<" ";
	cout<<sqrt(dis[2])/10<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}