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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
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
int p[maxn];
void solve()
{
	//cin>>n>>m;
	while(cin>>n>>m)
	{
		int len=(1<<m);
		for(int i=0;i<=len;i++)p[i]=0;
		for(int i=1;i<=n;i++)
		{
			int num=0;
			for(int j=1,x;j<=m;j++)
			{
				cin>>x;
				if(x==1)
					(num|=(1<<(j-1)));
			}
			p[num]++;
		}
		
		s=m+len+100;
		t=m+len+101;
		init();
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			add(i,t,x);
			add(t,i,0);
		}
		for(int i=0;i<len;i++)
		{
			add(s,i+1+m,p[i]);
			add(i+1+m,s,0);
			for(int j=1;j<=m;j++)
			{
				if(i&(1<<(j-1)))
				{
					add(i+1+m,j,p[i]);
					add(j,i+1+m,0);
				}
			}
		}
		int ans=DINIC(s,t);
		if(n==ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
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