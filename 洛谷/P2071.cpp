/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int d[maxn],q[maxn];
bitset<maxn>vis;
int n,m,s,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&d[y]==d[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)d[x]=0;
	return flow-out;
}
bool makelevel(int s,int t)
{
	for(int i=0;i<=n*3+2;i++)
		d[i]=0;
	queue<int>q;
	d[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(d[y]==0&&w>0)
			{
				q.push(y);
				d[y]=d[x]+1;
			}
		}
	}
	return false;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(makelevel(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		int x,y;
		cin>>x>>y;
		add(i,x+n*2,1);
		add(x+n*2,i,0);

		// add(i,x+n*2+n,1);
		// add(x+n*2+n,i,0);

		add(i,y+n*2,1);
		add(y+n*2,i,0);

		// add(i,y+n*2+n,1);
		// add(y+n*2+n,i,0);
	}
	// s=4*n+1;
	// t=4*n+2;
	s=n*3+1;
	t=n*3+2;
	for(int i=1;i<=n*2;i++)
		add(s,i,1),add(i,s,0);
	for(int i=n*2+1;i<=n*3;i++)
		add(i,t,2),add(t,i,0);
	int ans=DINIC(s,t);
	cout<<ans<<endl;
}
signed main()
{	
	//freopen("C:\\Users\\tob\\Desktop\\test\\P2071_2.in","r",stdin);
	//freopen("C:\\Users\\tob\\Desktop\\test\\P2071_3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}