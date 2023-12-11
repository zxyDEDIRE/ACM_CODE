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
const int maxn=600;
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
int f[maxn][maxn];
bitset<maxn>vis;
string mp[maxn];
int dis[maxn];
int n,m,T;
void add(int from,int to,int  w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dij(int now,int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
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
			int c=f[x][(now+DIS)%T];
			if(dis[y]>dis[x]+w+c)
			{
				dis[y]=dis[x]+w+c;
				q.push({y,dis[y]});
			}
		}
	}
	return dis[n];
}
void solve()
{
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		f[i][T]=0;
		for(int j=T-1;j>=0;j--)
		{
			if(mp[i][j]=='1')
				f[i][j]=0;
			else f[i][j]=f[i][j+1]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=0;i<T;i++)
		cout<<dij(i,1,n)<<" ";
	cout<<endl;
	
}
signed main(){
	freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","r",stdin);
	freopen("C:\\Users\\tob\\Desktop\\a.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// clock_t start, finish;
	// start = clock();
		solve();
	// finish = clock();
	// cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
*/