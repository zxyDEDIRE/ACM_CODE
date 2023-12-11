/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
/*
网络流+二分
或
网络流+双指针
*/
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
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
	memset(dep+1,0,sizeof(int)*tot);
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
			if(dep[y]==0&&w>0){
				q.push(y),dep[y]=dep[x]+1;
			}
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
	while(bfs(s,t)){
		ans+=dfs(s,INF,t);
	}
	return ans;
}
int mp[1011][30];
int num[maxn];
int out[maxn];
int in[maxn];
bool ok(int l,int r)
{
	init();
	for(int i=1;i<=n;i++)
		in[i]=++tot;
	for(int i=1;i<=m;i++)
		out[i]=++tot;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		add(s,in[i],1);
		add(in[i],s,0);
	}
	for(int i=1;i<=m;i++)
	{
		add(out[i],t,num[i]);
		add(t,out[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=l;j<=r;j++)
		{
			int y=mp[i][j];
			add(in[i],out[y],1);
			add(out[y],in[i],0);
		}
	}
	int ans=DINIC(s,t);
	return ans==n;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=m;i++)
		cin>>num[i];
	int j=m;
	while(!ok(j,m))j--;
	int len=m-j+1;
	for(int i=m-1;i-len+1>=1;i--)
	{
		int j=i-len+1;
		while(j+1<=i&&ok(j+1,i))
			j++;
		len=min(len,i-j+1);
	}
	cout<<len<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}