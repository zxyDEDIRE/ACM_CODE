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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int p[maxn];
int n,m1,m2,s,t;
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
void solve()
{
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)
		p[i]=0;
	vector<pii>v;
	for(int i=1;i<=m1;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		if(w==1)p[x]++;
		else p[y]++;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==1||y==1)p[1]++;
		else v.push_back(pair<int,int>(x,y));
	}
	int sum=0;
	s=n+v.size()+1;
	t=s+1;
	init();
	for(int i=0;i<v.size();i++)
	{
		sum++;
		int x=v[i].first;
		int y=v[i].second;
		int in=i+n+1;
		add(s,in,1);
		add(in,s,0);

		add(in,x,INF);
		add(x,in,0);


		add(in,y,INF);
		add(y,in,0);
	}
	for(int i=2;i<=n;i++)
	{
		sum+=p[i];
		add(s,i,p[i]);
		add(i,s,0);

		add(i,t,p[1]);
		add(t,i,0);
	}
	int res=DINIC(s,t);
	//cout<<sum<<" "<<res<<endl;
	if(res<sum)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}