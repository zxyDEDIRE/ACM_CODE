/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
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
int dis_a[maxn];
int dis_b[maxn];
bitset<maxn>vis;
vector<int>u;
int n,m,k;
void dij(int s,int *dis)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
	q.push({s,0});
	dis[s]=0;
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
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		u.push_back(x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dij(1,dis_a);
	dij(n,dis_b);
	sort(u.begin(),u.end(),[&](int x,int y){
		return dis_a[x]-dis_b[x]>dis_a[y]-dis_b[y];
	});
	int ans=0;
	int t=dis_b[u[0]];
	for(int i=1;i<k;i++)
	{
		ans=max(ans,dis_a[u[i]]+t+1);
		t=max(t,dis_b[u[i]]);
	}
	cout<<min(ans,dis_a[n])<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}