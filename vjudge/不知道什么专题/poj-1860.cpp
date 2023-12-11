#include<iostream>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e4;
const int N=111;
struct node{
	int x;
	double c,w;
	node(int _x,double _c,double _w){
		x=_x;c=_c;w=_w;
	}
};
vector<node>v[N];
bitset<maxn>vis;
double dis[N];
int n,m,s;
double num;
void spfa()
{
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		// for(auto [y,c,w]:v[x])
		for(int i=0;i<(int)v[x].size();i++)
		{
			int y=v[x][i].x;
			double c=v[x][i].c;
			double w=v[x][i].w;
			double now=(dis[x]-w)*c;
			if(dis[y]<now)
			{
				dis[y]=now;
				vis[y]=1;
				q.push(y);
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>s>>num;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		double a1,b1,a2,b2;
		cin>>x>>y>>a1>>b1>>a2>>b2;
		v[x].push_back(node(y,a1,b1));
		v[y].push_back(node(x,a2,b2));
	}
	dis[s]=num;
	spfa();
	if(dis[s]>num)cout<<"YES\n";
	else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
/*
010001110
010
100
000
001
011
111
110
*/