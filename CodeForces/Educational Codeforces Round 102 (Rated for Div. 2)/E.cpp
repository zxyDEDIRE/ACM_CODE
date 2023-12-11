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
const int maxn=1e6+100;
struct node{
	int id,dis,mi,ma;
	bool operator<(const node&a)const{
		return a.dis<dis; 
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
bitset<maxn>vis;
int head[maxn],cnt;
int ans[maxn];
int dis[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		ans[i]=INF;
	vis.reset();
	dis[s]=0;
	ans[s]=0;
	priority_queue<node>q;
	q.push({s,0ll,INF,0ll});
	while(!q.empty())
	{
		auto [x,DIS,mi,ma]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int MI=min(mi,w);
			int MA=max(ma,w);
			cout<<x<<" "<<ans[x]<<" "<<w<<" "<<MA<<" "<<MI<<" "<<ans[y]<<" "<<y<<endl;
			cout<<ans[x]+w-MA+MI<<" "<<ans[y]<<endl;
			if(!vis[y]&&dis[x]+w-MA+MI<ans[y])
			{
				cout<<"Yes"<<endl;
				ans[y]=dis[x]+w-MA+MI;
				dis[y]=dis[x]+w;
				q.push({y,ans[y],MI,MA});
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij(1);
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