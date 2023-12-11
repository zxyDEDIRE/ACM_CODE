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
const int N=1e3+10;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
bitset<maxn>vis;
int dis[maxn];
int mp[N][N];
int n;
int dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(i==x)continue;
			if(dis[i]>dis[x]+mp[x][i])
			{
				dis[i]=dis[x]+mp[x][i];
				q.push({i,dis[i]});
			}
		}
	}
	return dis[n];
}
void solve()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>mp[i][j];
		dij(1);
		int ans=dis[n];
		int m1=INF,m2=INF;
		for(int i=2;i<=n;i++)
			m1=min(m1,dis[i]+mp[i][1]);
		dij(n);
		for(int i=1;i<n;i++)
			m2=min(m2,dis[i]+mp[i][n]);
		cout<<min(ans,m1+m2)<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}