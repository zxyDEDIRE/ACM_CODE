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
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,w,c;
};
vector<Edge>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int n,m,h;
bool check(int mid)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	vis.reset();
	priority_queue<node>q;
	q.push({1,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(x==n&&dis[n]<=h)return 1;
		if(DIS>h)return 0;
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w,c]:v[x])
		{
			if(w<mid)continue;
			if(dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				q.push({y,dis[y]});
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<dis[i]<<" ";cout<<endl;
	return 0;
}
void solve()
{
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++){
		int x,y,w,c;
		cin>>x>>y>>w>>c;
		v[x].push_back({y,w,c});
		v[y].push_back({x,w,c});
	}

	int l=1,r=1e9;
	int ans=-1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		// cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
	cout<<ans<<endl;
	// cout<<check(2)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}