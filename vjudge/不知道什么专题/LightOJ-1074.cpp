#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
vector<pii>v[maxn];
bitset<maxn>vis,ok;
int dis[maxn];
int in[maxn];
int p[maxn];
int n,m,q;
void dfs(int x)
{
	ok[x]=1;
	for(auto [y,w]:v[x])
		if(!ok[y])
			dfs(y);
}
void spfa()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	q.push(1);
	dis[1]=0;
	in[1]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		if(ok[x])continue;
		// in[x]++;.
		// if(in[x]>n+1)dfs(x);.
		if(in[x]>n)dfs(x);
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				in[y]=in[x]+1;
				dis[y]=dis[x]+w;
					
				if(!vis[y]){
					q.push(y),vis[y]=1;
				}
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],v[i].clear();
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y;
		w=p[y]-p[x];
		v[x].push_back({y,w*w*w});
	}
	vis.reset();
	ok.reset();
	spfa();
	cin>>q;
	while(q--)
	{
		int x;cin>>x;
		if(ok[x]||dis[x]<3||dis[x]==INF)cout<<"?\n";
		else cout<<dis[x]<<"\n";
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);asdasd
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<":\n";
		solve();
	}
	return 0;
}