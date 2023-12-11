/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int siz[maxn];
int dp[maxn];
int ans;
int n,k;
void dfs1(int x,int D,int fa)
{
	dis[x]=D;
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,D+1,x);
		siz[x]+=siz[y];
	}
}
void dfs2(int x,int fa=0)
{
	(ans+=dp[x]+n-1)%=mod;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		(dp[y]=dp[x]+(n-siz[y])-siz[y])%=mod;
		dfs2(y,x);
	}
}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void solve()
{
	cin>>n>>k;
	if(k!=2){
		cout<<1<<endl;
		return ;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0,0);
	for(int i=1;i<=n;i++)
		dp[1]+=dis[i],vis[i]=0,dp[1]%=mod;
	ans=0;
	dfs2(1);
	ans=(ans*ksm(2,mod-2))%mod;
	int t=n*(n-1)%mod;
	t=(t*ksm(2,mod-2))%mod;
	ans=(ans*ksm(t,mod-2))%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 2
1 2
2 3
3 4
3 5

28 10

1 2 3 3
1 2 2
1 1
2

2+3+4+4=13
2+3+3=8=21
2+2=4=25
3=3=28


2 2
1 2

*/