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
const int N=444;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int s[maxn],t[maxn];
bitset<N>vis;
vector<pii>v[N];
int dis[N][N];
int dp[N][N];
int n,m;
void dij(int s)
{
	for(int i=1;i<=400;i++)
		dis[s][i]=INF;
	vis.reset();
	priority_queue<node>q;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[s][y]>dis[s][x]+w)
			{
				dis[s][y]=dis[s][x]+w;
				q.push({y,dis[s][y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
	}
	for(int i=1;i<=400;i++)
		dij(i);
	for(int i=1;i<=400;i++)
		for(int j=1;j<=400;j++){
			dp[i][j]=INF;
			for(int k=1;k<=400;k++)
				dp[i][j]=min(dp[i][j],dis[i][k]+dis[j][k]);
		}
	vector<int>v(444,0);
	for(int i=1;i<=n;i++)
		v[t[i]]++;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=400;j++)
			sum+=dp[s[i]][j]*v[j];
	}
	cout << fixed << setprecision(2) <<1.0*sum/n<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/