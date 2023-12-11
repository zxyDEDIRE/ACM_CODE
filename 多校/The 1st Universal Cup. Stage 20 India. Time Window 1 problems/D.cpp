/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int d1[maxn],c1[maxn];
int d2[maxn],c2[maxn];
int up[maxn];
int dp[maxn];
int f[maxn];
set<int>s;
int n,m,k;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void init()
{
	s.clear();
	for(int i=1;i<=n;i++)
	{
		d1[i]=d2[i]=c1[i]=c2[i]=up[i]=0;
		v[i].clear();
		f[i]=i;
	}
	vis.reset();
}
void dfs1(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa) continue;
		dfs1(y,x);
		if(d1[y]+1>d1[x])
		d2[x]=d1[x],c2[x]=c1[x],d1[x]=d1[y]+1,c1[x]=y;
		else if(d1[y]+1>d2[x])
		d2[x]=d1[y]+1,c2[x]=y;
	}
}
void dfs2(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa) continue;
		if(c1[x]!=y) up[y]=max(d1[x],up[x])+1;//不是从它更新来的
		else up[y]=max(d2[x],up[x])+1;
		dfs2(y,x);
	}
}
void dfs3(int x,int fa)
{
	// cout<<"SDF "<<x<<endl;
	int flag=0;
	for(auto y:v[x])
	{
		if(y!=fa)
		{
			flag=1;
			vis[y]=1;
			dis[y]=dis[x]+1;
			dfs3(y,x);
		}
	}
	// cout<<x<<" "<<dis[x]<<endl;
	if(dis[x]==0||dis[x]%k==0)
	{
		s.insert(x);
	}
	else if(flag==0)
	{
		if(dis[x]%k>(k/2))
			s.insert(x);
	}
}
void solve()
{
	cin>>n>>m;
	k=ceil(sqrt(n))*2;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y)) continue;
		v[x].push_back(y);
		v[y].push_back(x);
		f[find(x)]=find(y);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=0x3f3f3f3f,pos;
	for(int i=1;i<=n;++i)
	{
		if(max(up[i],d1[i])<ans) ans=max(up[i],d1[i]),pos=i;
	}


	dis[pos]=0;
	dfs3(pos,0);
	// cout<<"pos "<<pos<<endl;
	cout<<s.size()<<endl;
	for(auto i:s)
		cout<<i<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
9 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9

*/