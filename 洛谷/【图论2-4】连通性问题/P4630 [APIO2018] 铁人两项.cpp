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
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{int to,next;};
vector<vector<int>>v;
vector<int>dp;
vector<Edge>edge;
vector<int>head,low,dfn,p,siz;
stack<int>s;
int indx,cnt,tot;
ll ans;
int n,m,num;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	edge.resize(m*3+1);
	siz.resize(n*2+1);
	head.resize(n+1);
	low.resize(n+1);
	dfn.resize(n+1);
	dp.resize(n*2+1);
	p.resize(n*2+1);
	v.resize(n*2+1);
	indx=0;
	tot=n;
	cnt=1;
	ans=0;
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	num++;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				tot++;
				int _cnt=1;
				int r;
				p[x]=-1;
				siz[x]=1;
				siz[tot]=0;
				do{
					r=s.top();s.pop();
					_cnt++;p[r]=-1;siz[r]=1;
					v[r].push_back(tot);
					v[tot].push_back(r);
				}while(r!=y);
				v[x].push_back(tot);
				v[tot].push_back(x);
				p[tot]=_cnt;
			}
		}
		else if(i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x,int fa=0)
{
	vector<int>now;
	int sum=0;
	int cnt=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		now.push_back(y);sum+=dp[y];cnt+=siz[y];
		siz[x]+=siz[y];
		dp[x]+=dp[y];
		if(p[x]==-1)
			ans+=max(0ll,dp[y]+p[x]*(siz[y]))*2;
	}
	dp[x]+=p[x]*siz[x];
	for(auto y:now)
		ans+=dp[y]*(cnt-siz[y])+p[x]*(cnt-siz[y])*siz[y]+(sum-dp[y])*siz[y];
}
void dfs1(int x,int fa=0)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		ans+=p[x]*siz[x]*siz[y]*2;;
		siz[x]+=siz[y];
	}
	ans+=p[x]*siz[x]*(num-siz[x])*2;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]){
			num=0;
			tarjan(i);
			dfs1(i);
		}
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
4 4
1 2
2 3
3 4
4 1

7 8
1 2
2 3
3 4
4 2
1 5
5 6
6 7
7 5

*/