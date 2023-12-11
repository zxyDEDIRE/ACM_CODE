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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int N=1e6+100;
vector<pair<int,long long>>tr[N];
void add(int x,int y,long long w)
{
	tr[x].push_back({y,w});
}
int a[N];
int n,m;
long long t;
bool vis[N];
long long dis[N];
void Dis(int s)
{
	priority_queue<pair<long long,int>>q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=2e18;
		vis[i]=false;
		if((a[i]>>s)&1){
			q.push({0,i});
			dis[i]=0;
		}
	}
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<tr[u].size();i++)
		{
			int v=tr[u][i].first;
			long long w=tr[u][i].second;
			long long ww=dis[u]%m;
			if(dis[u]&&ww==0) ww=m;
			if(dis[v]>dis[u]+(ww>w?m-ww+w:-ww+w))
			{
				dis[v]=dis[u]+(ww>w?m-ww+w:-ww+w);
				q.push({-dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<=t) a[i]|=(1<<s);
	}
}
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(y,x,i);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<8;i++)
	{
		Dis(i);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
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
/*
4 4 3
1 2
2 3
1 2
3 4
0 1 2 4
*/