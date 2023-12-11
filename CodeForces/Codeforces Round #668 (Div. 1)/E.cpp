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
const int N=222;
char mp[N][N];
int xx[N][N];
int yy[N][N];
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	s=++tot;
	t=++tot;

	for(int i=1;i<=n;i++)
	{
		int fl=0;
		for(int j=1;j<=m;j++)
		{
			if(!fl&&mp[i][j]=='#')
			{
				fl=1;
				xx[i][j]=++tot;
				add(s,tot,1);
				add(tot,s,0);
			}
			else if(fl&&mp[i][j]=='#')
			{
				xx[i][j]=tot;
			}
			else if(mp[i][j]!='#')
				fl=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			if(!fl&&mp[i][j]=='#')
			{
				fl=1;
				yy[i][j]=++tot;
				add(tot,t,1);
				add(t,tot,0);
			}
			else if(fl&&mp[i][j]=='#')
			{
				yy[i][j]=tot;
			}
			else if(mp[i][j]!='#')
				fl=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='#')
			{
				add(xx[i][j],yy[i][j],1);
				add(yy[i][j],xx[i][j],0);
			}
		}
	}
	cout<<DINIC(s,t)<<endl;

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
/*
20 20
#.#.###..##.##..####
###.....####..###.##
..####.#....#####.#.
##...#.#.##.#.#.####
...#.#..###.#.##....
..#.##.#.##.#.##...#
#.#####..###.######.
##..#####.#.#.#####.
#####.##.####.######
###.#.#.####...####.
##...#..#.....####.#
..#####.##.#..#.####
.#..##..##......###.
###.##.#...##.######
##.#..##.###..#..###
#.##.#...#.#.#.....#
.#.###.#....#.###.#.
...#.##..#.##....###
#..###...###.####.##
##.#...##.#######.##
*/