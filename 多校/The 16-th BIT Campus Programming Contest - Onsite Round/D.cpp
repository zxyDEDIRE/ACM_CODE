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
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=700;
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
bitset<maxn>vis;
string mp[maxn];
int in[N][N],tot;
int dis[maxn];
int s[maxn],t;
int n,m,T;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int S)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
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
}
void solve()
{
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++){
		for(int j=0;j<T;j++)
			in[i][j]=++tot;
	}
	for(int i=0;i<T;i++)
		s[i]=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		cin>>mp[i];
	for(int i=0;i<T;i++)
	{
		if(mp[1][i]=='1')
		{
			// cout<<i<<" "<<in[1][i]<<endl;	
			add(s[i],in[1][i],0);
		}
		// add(in[1][i],s[i],0);

		add(in[n][i],t,0);
		// add(t,in[n][i],0);
	}
	for(int i=1;i<=n;i++)
	{
		int fl=-1;
		for(int j=0;j<T*2+2;j++)
		{
			if(mp[i][j%T]=='1')
			{
				if(fl!=-1)
				{
					// add(in[i][fl%T],in[i][j%T],j-fl);
					add(in[i][j%T],in[i][fl%T],j-fl);
				}
				fl=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		for(int j=0;j<T;j++)
		{
			if(mp[y][(j+w)%T]=='1'||y==n)
			{
				if(mp[x][j]=='1')
				{
					add(in[x][j],in[y][(j+w)%T],w);
				// add(in[y][(j+w)%T],in[x][j],w);
				}
			}
			if(mp[x][(j+w)%T]=='1'||x==n)
			{
				if(mp[y][j]=='1')
				{
					add(in[y][j],in[x][(j+w)%T],w);
					// add(in[x][(j+w)%T],in[y][j],w);
				}
			}
		}
	}
	// dij(s[4]);
	for(int i=0;i<T;i++)
	{
		dij(s[i]);
		cout<<dis[t]<<" ";
	}
	// cout<<endl;
	// cout<<endl;

	// for(int i=0;i<T;i++)
	// 	cout<<dis[in[1][i]]<<" ";cout<<endl;
	// cout<<endl;
	// for(int i=T-1;i>=0;i--)
	// 	dis[in[1][i]]=min(dis[in[1][i%T]],dis[in[1][(i+1)%T]]+1);
	// for(int i=T-1;i>=0;i--)
	// 	dis[in[1][i]]=min(dis[in[1][i%T]],dis[in[1][(i+1)%T]]+1);
	// // cout<<endl;
	// for(int i=0;i<T;i++)
	// 	cout<<dis[in[1][i]]<<" ";cout<<endl;
	// dij(s[4]);
	// cout<<dis[t]<<endl;

	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=0;j<T;j++)
	// 		printf("%10lld ",dis[in[i][j]]);
	// 	cout<<endl;
	// }

	// for(int i=0;i<T;i++)
	// {
	// 	dij(s[i]);
	// 	cout<<i<<" "<<dis[t]<<endl;
	// }
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
4 4 5
11111
00001
01000
00000
2 1 1
4 2 1
1 3 1
3 4 1

5 10 4
1001
1011
0010
0111
0110
2 5 0
2 5 4
2 5 2
1 5 3
3 5 2
2 5 4
1 5 2
1 5 4
3 5 2
4 5 2


*/