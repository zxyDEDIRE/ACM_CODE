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
#define double long double
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
	double t;
}edge[maxn],v[maxn];
int dfn[maxn],low[maxn],col[maxn],indx,tot;
vector<pii>G[maxn];
int head[maxn],cnt;
int h[maxn],cn;
bitset<maxn>vis;
int dp[maxn];
int in[maxn];
stack<int>s;
int w[maxn];
int n,m;
void add(int from,int to,int w)
{
	v[++cn].w=w;
	v[cn].to=to;
	v[cn].next=h[from];
	h[from]=cn;
}
void add(int from,int to,int w,double t){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].t=t;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
int f(int x,double y)
{
	int ans=0;
	while(x)
	{
		ans+=x;
		x=(int)(1.0*x*y);
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		double t;
		cin>>x>>y>>w>>t;
		add(x,y,w,t);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]){
			tarjan(i);
		}
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[y]==col[x])
				w[col[y]]+=f(edge[i].w,edge[i].t);
			else
				add(col[x],col[y],edge[i].w),in[col[y]]++;
		}
	}
	queue<int>q;
	int s;
	cin>>s;
	q.push(col[s]);
	// for(int i=1;i<=tot;i++)
	// 	if(!in[i])
	// 		q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		dp[x]+=w[x];
		for(int i=h[x];i;i=v[i].next)
		{
			int y=v[i].to;
			dp[y]=max(dp[y],v[i].w+dp[x]);
			q.push(y);
		}
	}
	int ma=0;
	for(int i=1;i<=tot;i++)
		ma=max(ma,dp[i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P2656_4.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	// cout<<f(3,0);
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
3 2
1 2 4 0.7
2 3 3 0.6
2
*/