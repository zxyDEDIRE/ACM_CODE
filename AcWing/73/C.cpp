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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
int n,ma;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int f,int dep)
{
	dis[x]=dep;
	ma=max(ma,dis[x]);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)continue;
		dfs(y,x,dep+edge[i].w);
	}
}
pii f(int x,int fa)
{
	int fw=0,fl=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(y==fa)continue;
		pii a=f(y,x);
		if(a.first==0)fl=10;
		else if(a.first==1)fw=w+a.second,ma=max(ma,fw);
		fl++;
	}
	if(fl<=1)return {1,fw};
	else return {0,0};
}
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
		sum+=w+w;
	}		
	dfs(1,0,0);
	cout<<sum-ma<<endl;
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