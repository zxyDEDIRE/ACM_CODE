/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,- 1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bool vis[maxn];
int n,m,ans;
void add(int from,int to)
{
	edge[++cnt].w=1;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int fa=0)
{
	vis[x]=1;
	// cout<<"X "<<x<<endl;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		// cout<<y<<" "<<w<<endl;
		if(y==fa||w==0)continue;
		if(vis[y])
		{
			ans++;
			edge[i].w=0;
			edge[i^1].w=0;
		}
		else dfs(y,x);
	}
}
void solve()
{
	cin>>n>>m;
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	cout<<ans<<endl;
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