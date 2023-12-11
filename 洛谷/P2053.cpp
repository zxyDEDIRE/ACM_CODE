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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
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
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	printf("%.2lf",1.0*maxc/n);
}
const int N=600;
int mp[N][N];
int b[N][N];
int a[N];
void solve()
{
	read(m);
	read(n);
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		a[i]=++tot;
		add(s,a[i],1,0);
		add(a[i],s,0,0);
		for(int j=1;j<=m;j++)
		{
			read(mp[i][j]);
			b[i][j]=++tot;
			add(b[i][j],t,1,0);
			add(t,b[i][j],0,0);
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			for(int i=1;i<=n;i++)
			{
				add(a[x],b[i][y],1,mp[x][y]*i);
				add(b[i][y],a[x],0,-mp[x][y]*i);
			}
		}
	}
	MCMF(s,t);
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}