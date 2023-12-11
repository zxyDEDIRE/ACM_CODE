/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int di,dis;
	bool operator<(const node &a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
string a[maxn],b[maxn];
bitset<maxn>vis;
int w[maxn];
int head[maxn],cnt;
int dis[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int t)
{
	cout<<s<<" "<<t<<endl;
	memset(dis,INF,sizeof(int)*((1<<n)+100));
	priority_queue<node>q;
	vis.reset();
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,XX]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>a[i]>>b[i];
	cout<<endl;
	for(int x=0;x<(1<<n);x++)
	{
		for(int y=1;y<=m;y++)
		{
			int flag=1;
			//包含全部+ 不包含任何-
			for(int i=0;i<n;i++)
			{
				if(a[y][i]=='+'&&(x|(1<<i))==1)flag=0;
				if(a[y][i]=='-'&&(x|(1<<i))==0)flag=0;
			}
			if(!flag)continue;
			int num=x;
			//修复- 造成+
			for(int i=0;i<n;i++)
			{
				if(b[y][i]=='-')num=(num|(1<<i));
				if(b[y][i]=='+'&&(num&(1<<i)))num^=((1<<i));
			}
			cout<<x<<" "<<num<<" "<<a[y]<<" "<<b[y]<<" "<<w[y]<<endl;
			add(x,num,w[y]);
		}
	}
	dij(0,(1<<n)-1);
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
111
*/