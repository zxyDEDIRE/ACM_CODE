/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int maxn=2e6+100;
struct Edge{
	int to,next,w;
}edge[maxn];
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int head[maxn],cnt;
int dis[maxn];
int d[maxn];
bitset<maxn>vis,ok;
int n,m,k;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	for(int i=1;i<=n;i++)
		head[i]=0;
	cnt=0;
	vis.reset();
	ok.reset();
}
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		if(ok[i]){
			q.push({i,0});
			d[i]=0;
		}
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(d[x]>0)
		{
			d[x]--;
			continue;
		}
		if(vis[x])continue;
		vis[x]=1;
		dis[x]=DIS;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(vis[y])continue;
			q.push({y,dis[x]+w});
		}
	}
	if(dis[1]==INF)cout<<-1<<endl;
	else cout<<dis[1]<<endl;
}
void solve()
{
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		ok[x]=1;
	}
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij();
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