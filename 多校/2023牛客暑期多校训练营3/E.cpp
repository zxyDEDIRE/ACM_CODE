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
vector<int>v[maxn];
// vector<int>G[maxn];
bitset<maxn>vis;
int dis[maxn];
int p[maxn];
int n,m,flag;
void init()
{
	flag=0;
	for(int i=1;i<=n;i++)
		v[i].clear(),p[i]=0;
}
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
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
				q.push({y,dis[y]});
			}
		}
	}
}
void dfs(int x)
{
	if(flag)return ;
	if(p[x]!=dis[x]){flag=1;return ;}
	vis[x]=1;
	sort(v[x].begin(),v[x].end(),[&](int a,int b){
		return dis[a]>dis[b];
	});
	for(auto y:v[x])
	{
		if(vis[y])continue;
		p[y]=p[x]+1;
		dfs(y);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	dij();
	vis.reset();
	dfs(1);

	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<i<<" "<<dis[i]<<" "<<p[i]<<endl;
	// }


	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
3 3
1 2
2 3
3 1
*/