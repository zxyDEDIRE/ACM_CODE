#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn],G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int in[maxn];
int cnt[maxn];
int w[maxn];
pii dis[maxn];
stack<int>s;
int n,m;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
			cnt[tot]++;
			num[tot]+=w[y];
		}while(x!=y);
	}
}
pii max(pii a,pii b)
{
	if(a.first!=b.first)
	{
		if(a.first<b.first)
			return b;
		else return a;
	}
	else
	{
		if(a.second<b.second)return a;
		else return b;
	}
}
void solve()
{
	cin>>n>>m;
	tot=indx=0;
	vis.reset();
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=col[i]=num[i]=cnt[i]=in[i]=0;
		cin>>w[i];
		dis[i]={0,0};
		v[i].clear();
		G[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]);
	for(int i=1;i<=tot;i++)
	{
		sort(G[i].begin(),G[i].end());
		G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
		for(auto y:G[i])
			in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(in[i]==0){
			q.push(i);
			dis[i]={cnt[i],num[i]};
		}
	pii ma={0,0};
	while(!q.empty())
	{
		int x=q.front();q.pop();
		ma=max(ma,dis[x]);
		for(auto y:G[x])
		{
			pii now={dis[x].first+cnt[y],dis[x].second+num[y]};
			in[y]--;
			if(now.first>dis[y].first)
			{
				dis[y]=now;
			}
			else if(now.first==dis[y].first&&now.second<dis[y].second)
			{
				dis[y]=now;
			}
			if(!in[y])
				q.push(y);
		}
	}
	cout<<ma.first<<" "<<ma.second<<endl;
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
D>B>E
*/