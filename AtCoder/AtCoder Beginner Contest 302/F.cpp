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
const int maxn=5e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int pre[maxn];
int n,m,tot,S,T;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int S,int T)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<node>q;
	q.push({S,0});
	dis[S]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
	if(dis[T]==INF)cout<<-1<<endl;
	else cout<<dis[T]<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		pre[i]=0;
	S=++tot;
	T=++tot;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		int mid=++tot;
		for(int j=0,x;j<k;j++)
		{
			cin>>x;
			pre[x]=++tot;
			v[x].push_back(pre[x]);
			add(mid,pre[x],0);
			add(pre[x],mid,0);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int mid=++tot;
		for(auto x:v[i])
		{
			add(mid,x,0);
			add(x,mid,1);
		}
	}
	for(auto x:v[1])
		add(S,x,0);
	for(auto x:v[m])
		add(x,T,0);
	dij(S,T);
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

aaaa
aaa

a a
a aa
a aaa
aa a
aa aa
aa aaa
aaa a
aaa aa
aaa aaa

*/