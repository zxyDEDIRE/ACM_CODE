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
const int maxn=4e5+100;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int num[maxn][40][2];
bitset<40>f[maxn];
bitset<maxn>vis;
int n,m,flag;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void doit(int x,int y,int w)
{
	for(int i=31;i>=0;i--)
	{
		if(w>=(1ll<<i))
		{
			w-=(1ll<<i);
			f[y][i]=(f[x][i]^1);
		}
		else
			f[y][i]=f[x][i];
	}
	for(int i=31;i>=0;i--)
	{
		if(f[y][i]==1)num[y][i][1]++;
		else num[y][i][0]++;
	}
}
void check(int x,int y,int w)
{
	for(int i=31;i>=0;i--)
	{
		if(w>=(1ll<<i))
		{
			w-=(1ll<<i);
			if(f[x][i]==f[y][i])flag=1;
		}
		else if(f[x][i]!=f[y][i])flag=1;
	}
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(vis[y])
			check(x,y,edge[i].w);
		else if(!vis[y])
		{
			doit(x,y,edge[i].w);
			dfs(y);
			for(int j=31;j>=0;j--)
			{
				num[x][j][0]+=num[y][j][0];
				num[x][j][1]+=num[y][j][1];
			}
		}
		
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
			cout<<i<<endl;
			for(int j=31;j>=0;j--){
				cout<<num[i][j][0]+1<<" "<<num[i][j][1]<<endl;
				ans+=min(num[i][j][0]+1,num[i][j][1])*(1ll<<j);
			}
			cout<<endl;
		}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<endl;
	if(flag){
		cout<<-1<<endl;
		return ;
	}
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