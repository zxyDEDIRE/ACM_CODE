/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int maxn=1e3;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
bitset<maxn>vis;
int dis[maxn];
bool ok[maxn][maxn];
int last[maxn];
int n,m,k,e,d;
void dij(int s=1)
{
	for(int i=1;i<=m;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
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
				last[y]=x;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	cin>>d;
	for(int i=1;i<=d;i++)
	{
		int p,a,b;
		cin>>p>>a>>b;
		for(int j=a;j<=b;j++)
			ok[p][j]=1;
	}

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