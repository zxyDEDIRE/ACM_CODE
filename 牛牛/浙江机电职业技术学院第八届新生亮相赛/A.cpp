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
const int N=1000;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
bool vis[N];
int dis[N];
int id[N];
int n,p,c;
int dij(int s)
{
	for(int i=1;i<=p;i++)
		dis[i]=INF,vis[i]=0;
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
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
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=dis[id[i]];
	return ans;
}
void solve()
{
	cin>>n>>p>>c;
	for(int i=1;i<=n;i++)
		cin>>id[i];
	for(int i=1;i<=c;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	int ma=INF;
	for(int i=1;i<=p;i++)
		ma=min(ma,dij(i));
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}