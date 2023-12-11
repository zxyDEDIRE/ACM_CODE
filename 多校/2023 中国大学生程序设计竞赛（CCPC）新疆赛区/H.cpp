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
bool vis[maxn];
int dis[maxn];
void init(int N)
{
	vector<int>p;
	for(int i=1;i<=N;i++)
		dis[i]=INF;
	priority_queue<node>q;
	for(int i=1;i*i<=N;i++)
		p.push_back(i*i),dis[i*i]=1,q.push({i*i,1});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:p)
		{
			if(i+x>N)break;
			int y=i+x;
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
}
int n;
void solve()
{
	cin>>n;
	init(n);
	ll ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans*dis[i])%mod;
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