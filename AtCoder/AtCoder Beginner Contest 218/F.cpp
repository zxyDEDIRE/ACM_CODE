/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn],G[maxn];
bitset<maxn>vis,T;
int dis[maxn];
int n,m;
void dij(int fl,int un)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push({1,0});
	vis.reset();
	dis[1]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(w==un)continue;
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	if(!fl)return ;
	vis.reset();
	q.push({n,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,id]:G[x])
		{
			if(dis[x]==dis[y]+1)
			{
				T[id]=1;
				q.push({y,0});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,i});
		G[y].push_back({x,i});
	}
	dij(1,0);
	int ans=dis[n];
	if(ans==INF){
		for(int i=1;i<=m;i++)
			cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=;im++)
	{
		if(T[i])
		{
			dij(0,i);
			if(dis[n]==INF)cout<<-1<<endl;
			else cout<<dis[n]<<endl;
		}
		else cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}