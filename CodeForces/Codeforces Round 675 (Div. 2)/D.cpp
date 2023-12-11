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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6;
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
map<pii,int>mp;
int dis[maxn];
pii p[maxn];
int sx,sy,tx,ty;
int n,m,tot;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int t)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<node>q;
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
	cin>>n>>m;
	cin>>sx>>sy>>tx>>ty;
	tot=0;
	mp[{sx,sy}]=++tot;
	mp[{tx,ty}]=++tot;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i]={x,y};
		mp[{x,y}]=++tot;
	}
	sort(p+1,p+1+m,[&](pii a,pii b){
		return a.first<b.first;
	});
	for(int i=1;i<=m;i++)
	{
		int x=mp[p[i]];
		int y=mp[p[i+1]];
		add(1,x,abs(sx-p[i].first));
		if(i==m)continue;
		int w=p[i+1].first-p[i].first;
		add(x,y,w);
		add(y,x,w);
	}
	sort(p+1,p+1+m,[&](pii a,pii b){
		return a.second<b.second;
	});
	for(int i=1;i<=m;i++)
	{
		int x=mp[p[i]];
		int y=mp[p[i+1]];
		add(1,x,abs(sy-p[i].second));
		if(i==m)continue;
		int w=p[i+1].second-p[i].second;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=1;i<=m;i++)
	{
		int x=mp[p[i]];
		int w=abs(p[i].first-tx)+abs(p[i].second-ty);
		//cout<<p[i].first<<" "<<p[i].second<<" "<<w<<endl;
		add(x,2,w);
	}
	add(1,2,abs(sx-tx)+abs(sy-ty));
	add(2,1,abs(sx-tx)+abs(sy-ty));
	dij(1,2);
	// for(int i=1;i<=tot;i++)
	// 	cout<<dis[i]<<" ";cout<<endl;
	cout<<dis[2]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 3
1 1 1 5
5 1
5 5
2 5

*/