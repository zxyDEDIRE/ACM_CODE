#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
const int maxn=1e3+10;
struct Edge{
	int to,next;
	double w;
}edge[maxn];
int head[maxn],cnt;
map<string,int>mp;
double dis[maxn][maxn];
bool vis[maxn];
double p[maxn];
int in[maxn];
int tot;
int n,m;
void add(int from,int to,double w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	for(int i=1;i<=cnt;i++)
		head[i]=0;
	mp.clear();
	cnt=tot=0;
}
bool spfa(int s)
{
	for(int i=1;i<=n;i++)
		p[i]=vis[i]=in[i]=0;
	p[s]=1;
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		in[x]++;
		if(in[x]==n+1)return 1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			double w=edge[i].w;
			if(p[y]<p[x]*w)
			{
				p[y]=p[x]*w;
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	
	return p[s]>1;
}
void solve()
{
	init();
	for(int i=1;i<=n;i++){
		string str;cin>>str;
		mp[str]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string x,y;
		double w;
		cin>>x>>w>>y;
		if(!mp.count(x))continue;
		if(!mp.count(y))continue;
		add(mp[x],mp[y],w);
	}
	for(int i=1;i<=1;i++)
		if(spfa(i)){
			cout<<"Yes\n";
			return ;
		}
	cout<<"No\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c=0;
	while(cin>>n&&n){
		cout<<"Case "<<++c<<": ";
		solve();
	}
	return 0;
}
/*
3
USDollar
BritishPound
FrenchFranc
3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar
0
*/