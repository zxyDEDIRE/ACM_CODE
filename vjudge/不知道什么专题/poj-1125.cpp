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
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
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
int h[maxn];
string a[maxn],b[maxn],c[maxn];
int aa,bb,cc;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i]>>a[i]>>b[i]>>c[i];
	s=n+1;
	t=n+2;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(h[i]-h[j])>40)continue;
			if(a[i]==a[j])continue;
			if(b[i]!=b[j])continue;
			if(c[i]==c[j])continue;
			if(a[i]=="F")
			{
				
				add(i,j,1);
				add(j,i,0);
			} 
			if(a[j]=="F")
			{
				add(j,i,1);
				add(i,j,0);
			}
		}
		if(a[i]=="F")
		{
			add(s,i,1);
			add(i,s,0);
		}
		else
		{
			add(i,t,1);
			add(t,i,0);
		}
	}
	cout<<n-DINIC(s,t)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}