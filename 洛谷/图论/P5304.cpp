#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=3e6+100;
struct node{
	int id;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
vector<vector<int>>bcc;
vector<vector<int>>bss;
vector<pii>v[maxn];
vector<int>D[maxn];
bitset<maxn>vis,ok;
stack<int>s;
ll dis[maxn];
int in[maxn];
ll res=INF;
int n,m,k;
void init()
{
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=vis[i]=in[i]=ok[i]=0;
		v[i].clear();
		D[i].clear();
	}
	for(int i=0;i<tot;i++)
	{
		D[i].clear();
	}
	bcc.clear();
	bss.clear();
	tot=indx=0;
	res=INF;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto [y,w]:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		bcc.push_back(vector<int>());
		bss.push_back(vector<int>());
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;col[y]=tot;
			if(ok[y])bss.back().push_back(y);
			bcc.back().push_back(y);
		}while(x!=y);
		tot++;
	}
}
void dij_bss(int s,int _x)
{
	vis.reset();
	priority_queue<node>q;
	dis[s]=0;
	vis[s]=1;
	q.push({s,0ll});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(DIS>dis[x])continue;
		if(ok[x]&&x!=s){
			res=min(res,DIS);
			return ;
		}
		for(auto [y,w]:v[x])
		{
			if(col[y]!=_x)continue;
			if(!vis[y])vis[y]=1,dis[y]=INF;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void dij(int _x)
{
	priority_queue<node>q;
	for(auto x:bcc[_x])
		q.push({x,dis[x]});
	vis.reset();
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		// if(DIS>dis[x])continue;
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				if(col[y]==_x)
					q.push({y,dis[y]});
			}
		}
	}
	for(auto x:bss[_x])
	{
		res=min(res,dis[x]);
		dis[x]=0;
		q.push({x,0ll});
	}
	vis.reset();
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		// if(DIS>dis[x])continue;
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
	}
	for(int i=1,x;i<=k;i++){
		cin>>x;
		if(ok[x])res=0;
		else ok[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<tot;i++)
	{
		if(bss[i].size()==0)continue;
		if(bcc[i].size()==1)continue;
		for(auto x:bss[i])
			dij_bss(x,col[x]);
	}
	for(int x=1;x<=n;x++)
	{
		for(auto [y,w]:v[x])
			if(col[x]!=col[y])
				D[col[x]].push_back(col[y]),in[col[y]]++;
		dis[x]=INF;
	}
	queue<int>q;
	for(int i=0;i<tot;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		dij(x);
		for(auto y:D[x])
		{
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	cout<<res<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

6 7 3
1 5 3
2 3 5
1 4 3
5 3 2
4 6 5
4 3 7
5 6 4
1 3 6

7 7 4
5 3 10
6 2 7
1 2 6
5 4 2
4 3 4
1 7 3
7 2 4
1 2 5 3
*/