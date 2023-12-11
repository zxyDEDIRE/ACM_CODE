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
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*n);
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
int out[30][30];
int in[30][30];
int d,num;
bool check(int a,int b,int x,int y)
{
	int dis=(a-x)*(a-x)+(b-y)*(b-y);
	if(dis>d*d)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m>>d;
	init();
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			in[i][j]=++tot,out[i][j]=++tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			int x=ch-'0';
			add(in[i][j],out[i][j],x);
			add(out[i][j],in[i][j],0);
		}
	s=++tot;
	t=++tot;
	num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;cin>>ch;
			if(ch=='L')
			{
				num++;
				add(s,in[i][j],1);
				add(in[i][j],s,0);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int ii=0;ii<=n+1;ii++)
			{
				for(int jj=0;jj<=m+1;jj++)
				{
					if(check(i,j,ii,jj))continue;
					if(ii<1||ii>n||jj<1||jj>m)
					{
						add(out[i][j],t,INF);
						add(t,out[i][j],0);
					}
					else
					{
						add(out[i][j],in[ii][jj],INF);
						add(in[ii][jj],out[i][j],0);
					}
				}
			}
		}
	}
	int ans=DINIC(s,t);
	cout<<num-ans<<endl;
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