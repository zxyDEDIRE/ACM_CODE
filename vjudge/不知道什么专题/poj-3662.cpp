/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(int x,int y){
		id=x,dis=y;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int n,m,k;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool check(int mid)
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	priority_queue<node>q;
	q.push(node(1,0));
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		if(x==n&&dis[n]<=k)return 1;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int t=0;
			if(edge[i].w>mid)t=1;
			if(dis[y]>dis[x]+t)
			{
				dis[y]=dis[x]+t;
				q.push(node(y,dis[y]));
			}
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	int l=-1,r=1000011,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(ans==1000011)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}
/*
5 7 100
1 2 5
3 1 4
2 4 8
3 2 3
5 2 9
3 4 7
4 5 6
*/