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
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int x,dis;
	bool operator<(const node&a)const{
		if(a.dis!=dis)return a.dis>dis;
		return a.x<x;
	}
};
vector<int>v[maxn];
bool vis[maxn];
int dis[maxn];
int in[maxn];
int h[maxn];
set<node>s;
int n,m,k;
void dfs(int x)
{
	vis[x]=1;
	s.erase(s.find({x,dis[x]}));
	dis[x]+=k;
	s.insert({x,dis[x]});
	for(auto y:v[x])
	{
		if(dis[y]<dis[x])
			dfs(y);
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>h[i],v[i].clear(),dis[i]=0,vis[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	queue<int>q;
	s.clear();
	int mi=INF,ma=0;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i),dis[i]=h[i];
	while(!q.empty()){
		int x=q.front();q.pop();
		s.insert({x,dis[x]});
		mi=min(mi,dis[x]);
		ma=max(ma,dis[x]);
		for(auto y:v[x])
		{
			in[y]--;
			if(h[y]>=h[x])dis[y]=max(dis[y],dis[x]+h[y]-h[x]);
			else dis[y]=max(dis[y],dis[x]+k-h[x]+h[y]);
			if(!in[y])q.push(y);
		}
	}


	int ans=ma-mi;
	while(1)
	{
		auto now=*s.begin();
		auto [x,DIS]=now;
		if(vis[x])break;
		dfs(x);
		ans=min(ans, (*s.rbegin()).dis-(*s.begin()).dis);
	}
	cout<<ans<<endl;
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