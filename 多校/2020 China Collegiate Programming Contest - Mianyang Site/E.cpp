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
const int N=5e5;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dp[N][66];//dp[i][j] 走了j步
int out[maxn];
int cut[maxn];
int n,m,k;
void clear()
{
	memset(head+1,0,sizeof(int)*cnt);
	memset(cut+1,0,sizeof(int)*n);
	memset(out+1,0,sizeof(int)*n);
	cnt=0;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void bfs()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=INF;
	queue<pii>q;
	for(int j=0;j<=k;j++)
		dp[n][j]=0,q.push({n,j});
	while(!q.empty())
	{
		auto [x,step]=q.front();q.pop();
		//还可以走step-1步
		if(step>0)//主动走,最短路
		{
			for(int i=head[x];i;i=edge[i].next)
			{
				int y=edge[i].to;
				if(dp[y][step-1]>dp[x][step]+1)
				{
					dp[y][step-1]=dp[x][step]+1;
					q.push({y,step-1});
				}
			}
		}
		else
		{
			//最长路 漂流 拓扑
			for(int i=head[x];i;i=edge[i].next)
			{
				int y=edge[i].to;
				if(edge[i].w)continue;
				out[y]--;
				if(!out[y])
				{
					for(int j=0;j<=k;j++)
					{
						if(dp[y][j]>dp[x][step]+1)
						{
							dp[y][j]=dp[x][step]+1;
							q.push({y,j});
						}
					}
				}
			}
			if(cut[x])
			{
				for(int j=0;j<=k;j++)
				{
					if(dp[x][j]>dp[x][step]+1)
					{
						dp[x][j]=dp[x][step]+1;
						q.push({x,j});
					}
				}
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	clear();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y,1);
		add(y,x,0);
		out[x]++;
	}
	for(int i=1;i<=n;i++)
		if(!out[i])cut[i]=1;
	bfs();
	for(int i=1;i<=n;i++)
		cout<<(dp[i][0]==INF?-1:dp[i][0])<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++)
	{
		cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}