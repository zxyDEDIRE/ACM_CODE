#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
struct Node{
	ll id;ll dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
bitset<maxn>vis;
ll dis[maxn];
ll x,y,z,h;
void dij()
{
	for(int i=0;i<x;i++)
		dis[i]=LLONG_MAX;
	vis.reset();
	priority_queue<Node>q;
	q.push({0,0});
	dis[0]=0;
	while(!q.empty())
	{
		auto [x,W]=q.top();q.pop();
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
	cin>>h>>x>>y>>z;
	if(x==1 || y==1 || z==1){cout<<h;return ;}
	h--;
	if(x>y)swap(x,y);
	if(x>z)swap(x,z);
	for(int i=0;i<x;i++)
	{
		v[i].push_back({(i+y)%x,y});
		v[i].push_back({(i+z)%x,z});
	}
	dij();
	ll ans=0;
	for(int i=0;i<x;i++)
		if(dis[i]<=h)
		ans+=(h-dis[i])/x+1;
	// for(int i=0;i<x;i++)
	// 	cout<<"I "<<i<<" "<<dis[i]<<" "<<((h-dis[i])/x+1)<<endl;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}