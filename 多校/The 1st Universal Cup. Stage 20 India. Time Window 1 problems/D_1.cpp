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
int siz[maxn],wgt[maxn];
bitset<maxn>vis;
int dis[maxn];
int mi=INF,ans;
int f[maxn];
set<int>s;
int n,m,k;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void init()
{
	mi=INF;
	s.clear();
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		f[i]=i;
	}
	vis.reset();
}
void dfs(int x,int fa)
{
    siz[x]=1;
    wgt[x]=0;
    for(auto y:v[x])
    {
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        wgt[x]=max(wgt[x],siz[y]);
    }
    wgt[x]=max(wgt[x],n-siz[x]);
    if(wgt[x]<mi) mi=wgt[x],ans=x;
}

void dfs2(int x)
{
	int flag=0;
	for(auto y:v[x])
	{
		if(!vis[y])
		{
			flag=1;
			vis[y]=1;
			dis[y]=dis[x]+1;
			dfs2(y);
		}
	}
	if(flag==0)
	{
		// cout<<x<<" "<<dis[x]<<" "<<dis[x]%k<<endl;
		if(dis[x]%k>(k/2))
			s.insert(x);
		else if(dis[x]==0)
			s.insert(x);
	}
	else if(dis[x]%k==0)
	{
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
	dfs(1,0);
	dis[ans]=0;
	dfs2(ans);
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