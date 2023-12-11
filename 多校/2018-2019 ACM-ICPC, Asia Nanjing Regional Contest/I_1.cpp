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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*tot);
	queue<int>q;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dep[y]==0&&w>0)
				q.push(y),dep[y]=dep[x]+1;
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
int in_1[maxn];
int in_2[maxn];
int k;
void solve()
{
	cin>>n>>m>>k;
	init();
	s=++tot;
	t=++tot;
	int T=++tot;
	add(s,T,k);
	add(T,s,0);
	for(int i=1;i<=n;i++)
	{
		in_1[i]=++tot;
		add(s,in_1[i],1);
		add(in_1[i],s,0);

		add(T,in_1[i],1);
		add(in_1[i],T,0);
	}
	for(int i=1;i<=m;i++)
	{
		in_2[i]=++tot;
		add(in_2[i],t,1);
		add(t,in_2[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		while(k--)
		{
			int x;cin>>x;
			add(in_1[i],in_2[x],1);
			add(in_2[x],in_1[i],0);
		}
	}
	int ans=DINIC(s,t);
	ans=min(ans,n+k);
	cout<<ans<<endl;
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
3 5 2
4 1 2 3 5
2 2 5
2 1 2

5 10 2
2 3 10
5 1 3 4 6 10
5 3 4 6 8 9
3 1 9 10
5 1 3 6 7 10


3 4 0
4 1 2 3 4
1 2
1 2
*/