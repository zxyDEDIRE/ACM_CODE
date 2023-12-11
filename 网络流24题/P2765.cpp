/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dep[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(dep+1,0,sizeof(int)*t);
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
	memset(dep+1,0,sizeof(int)*t);
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w&&!dep[y])
				dep[y]=dep[x]+1,q.push(y);
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
		if(w&&dep[y]==dep[x]+1)
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
int in[maxn],out[maxn],tot;
bitset<maxn>vis;
vector<int>v[maxn];
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	cout<<x<<" ";
	if(v[x].size())
	dfs(v[x][0]);
}
map<int,int>mp;
map<int,int>MMP;
void solve()
{
	cin>>n;

	s=1;
	t=2;
	tot=2;
	int num=0,i;
	for(i=1;;i++)
	{
		in[i]=++tot;
		MMP[tot]=i;
		out[i]=++tot;
		mp[tot]=i;
		add(s,in[i],1);
		add(in[i],s,0);

		add(out[i],t,1);
		add(t,out[i],0);

		for(int j=1;j<i;j++)
		{
			int x=sqrt(i+j);
			if(x*x==(i+j))
			{
				add(in[i],out[j],1);
				add(out[j],in[i],0);
			}
		}
		int ans=DINIC(s,t);
		if(ans==0)num++;
		if(num>n)break;
	}
	cout<<i-1<<endl;
	// for(int x=1;x<i;x++)
	// {
	// 	int flag=-1;
	// 	for(int i=head[in[x]];i;i=edge[i].next)
	// 	{
	// 		if(mp[edge[i].to]==0)continue;
	// 		if(edge[i].w==0&&edge[i^1].w!=0)
	// 		{
	// 			flag=mp[edge[i].to];
	// 			break;
	// 		}
	// 	}
	// 	if(flag!=-1)
	// 	{
	// 		v[flag].push_back(x);
	// 	}
	// }
	// cout<<"Yes"<<endl;
	// for(int x=1;x<i;x++)
	// {
	// 	if(vis[x])continue;
	// 	dfs(x);
	// 	cout<<endl;
	// }
	for(int x=1;x<i;x++)
	{
		if(vis[x])continue;
		int top=x;
		while(1)
		{
			if(vis[top])break;
			vis[top]=1;
			cout<<top<<" ";
			for(int i=head[out[top]];i;i=edge[i].next)
			{
				int y=MMP[edge[i].to];
				if(!y)continue;
				top=y;
			}
		}
		cout<<endl;
	}

}
signed main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}