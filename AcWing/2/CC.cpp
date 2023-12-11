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
struct node{
	int id,dis,i;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w,id;
}edge[maxn];
int head[maxn],cnt=1;
bitset<maxn>vis;
bitset<maxn>ok;
int dis[maxn];
int n,m,k,ma;
void add(int from,int to,int w,int id)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].id=id;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=1e18;
	priority_queue<node>q;
	vector<int>v;
	q.push({s,0,-1});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS,I]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		v.push_back(I);
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y],edge[i].id});
			}
		}
	}
	cout<<min((int)v.size()-1,k)<<endl;
	for(int i=1;i<=min((int)v.size()-1,k);i++)
		cout<<(v[i])<<" ";
	cout<<endl;

}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w,i);
		add(y,x,w,i);
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