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
void f(int x,int y,int w)
{
	add(x,y,w);
	add(y,x,0);
}
const int N=222;
vector<int>v[maxn];
int dis[N][N];
int val[maxn];
int in[maxn];
int w[maxn],sum;
void solve()
{
	init();
	cin>>n;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
		cin>>val[i],sum+=val[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
	{
		in[i]=++tot;
		add(s,in[i],w[i]);
		add(in[i],s,0);
	}
	for(int i=1;i<=n;i++)
	{
		int ma=0;
		vector<pii>v;
		vector<int>u;
		for(int j=1;j<=n;j++)
			v.push_back({j,dis[i][j]}),ma=max(ma,dis[i][j]);
		sort(v.begin(),v.end(),[&](pii a,pii b){
			return a.second<b.second;
		});

		int now=0,fl=++tot;
		add(tot,t,val[0]);
		for(int i=0;i<v.size();i++)
		{
			auto [x,y]=v[i];
			if(y==now)
			{
				add(x,tot,INF);
				add(tot,x,0);
			}
			else
			{
				u.push_back(tot);
				++tot;
				for(auto i:u)
				{
					add(in[i],tot,INF);
					add(tot,in[i],0);
				}
				now=y;
				add(tot,t,(now>=ma?val[n-1]:val[now]));
				add(t,tot,0);
			}
		}
	}
	cout<<sum-DINIC(s,t)<<endl;


	// init();
	// cin>>n;
	// s=++tot;
	// t=++tot;
	// for(int i=1;i<=n;i++)
	// {
	// 	in[i]=++tot;
	// 	cin>>w[i];
	// 	add(s,in[i],w[i]);
	// 	add(in[i],s,0);
	// }
	// for(int i=0;i<n;i++)
	// 	cin>>val[i];

	// tot++;
	// f(in[1],tot,INF);
	// f(tot,t,val[0]);

	// // tot++;
	// // f(tot-1,tot,INF);
	// // f(in[2],tot,INF);
	// // f(in[3],tot,INF);
	// // f(tot,t,val[2]);

	// tot++;
	// f(in[1],tot,INF);
	// f(in[2],tot,INF);
	// f(in[3],tot,INF);
	// f(tot,t,val[2]);

	// tot++;
	// f(in[1],tot,INF);
	// f(in[2],tot,INF);
	// f(in[3],tot,INF);
	// f(tot,t,val[2]);

	// cout<<12-DINIC(s,t)<<endl;

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