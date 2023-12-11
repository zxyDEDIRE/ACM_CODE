/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>G[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
bool ok[maxn];
int p[maxn];
int n,m,k;
ll ans=0;
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,ok[i]=0;
	priority_queue<node>q;
	q.push({1,0});
	dis[1]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				p[y]=x;
				q.push({y,dis[y]});
			}
		}
	}
}
void dfs(int x,int dep)
{
	ans++;
	for(auto y:G[x])
		if(dep<k)
			dfs(y,dep+1);
	if(v[x].size()==1&&x!=1)
	{
		ans+=1ll*k-dep;
	}
	else
	{
		ans+=1ll*(k-dep)*max(0,int(v[x].size()-G[x].size()-1));
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dij();
	for(int i=1;i<=n;i++)
		if(p[i]){
			G[p[i]].push_back(i);
		}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 1 2
1 2
*/