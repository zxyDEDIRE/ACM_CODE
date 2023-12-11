/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=3e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Seg{
	int l,r,in,out;
}t[maxn];
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int n,m,s,tot;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void build(int rt,int l,int r,int fa)
{
	t[rt]={l,r,++tot,++tot};
	if(fa)add(fa-1,tot-1,0),add(tot,fa,0);
	if(l==r){
		add(l,tot,0);
		add(tot-1,l,0);
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid,t[rt].out);
	build(rt<<1|1,mid+1,r,t[rt].out);
}
void add_1(int rt,int x,int l,int r,int w)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		add(x,t[rt].in,w);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add_1(rt<<1,x,l,r,w);
	if(r>mid)add_1(rt<<1|1,x,l,r,w);
}
void add_2(int rt,int x,int l,int r,int w)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		add(t[rt].out,x,w);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add_2(rt<<1,x,l,r,w);
	if(r>mid)add_2(rt<<1|1,x,l,r,w);
}
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
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
	for(int i=1;i<=n;i++)
		if(dis[i]!=INF)cout<<dis[i]<<" ";
		else cout<<-1<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>m>>s;
	tot=n;
	build(1,1,n,0);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
		}
		else if(op==2)
		{
			int x,l,r,w;
			cin>>x>>l>>r>>w;
			add_1(1,x,l,r,w);
		}
		else if(op==3)
		{
			int x,l,r,w;
			cin>>x>>l>>r>>w;
			add_2(1,x,l,r,w);
		}
	}
	dij(s);
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