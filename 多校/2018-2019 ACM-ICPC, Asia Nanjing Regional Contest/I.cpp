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
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
int in_1[maxn];
int in_2[maxn];
int k;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
void MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	int ans=0;
	while(spfa(s,t))
	{
		if(flow[t]>=2)
		{
			if(k>0)ans+=2,k--;
			else ans++;
		}
		else ans+=flow[t];
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	cout<<ans<<endl;
	// cout<<maxf<<" "<<maxc<<endl;
}

void solve()
{
	cin>>n>>m>>k;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		in_1[i]=++tot;
	for(int j=1;j<=m;j++)
		in_2[j]=++tot;
	for(int i=1;i<=n;i++)
	{
		add(s,in_1[i],2,0);
		add(in_1[i],s,0,0);
	}
	for(int i=1;i<=m;i++)
	{
		add(in_2[i],t,1,0);
		add(t,in_2[i],0,0);
	}
	for(int i=1;i<=n;i++)
	{
		int q;cin>>q;
		while(q--)
		{
			int x;
			cin>>x;
			add(in_1[i],in_2[x],1,0);
			add(in_2[x],in_1[i],0,0);
		}
	}
	MCMF(s,t);
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
*/