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
int siz[maxn];
int len[maxn];
int dep[maxn];
ll dp[maxn];
int a[maxn];
ll ans=0;
int n;
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

int f(int x){
	int cnt=0;
	while(x){
		x/=10;cnt++;
	}
	return cnt;
}
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dep[y]=dep[x]+len[y];
		dfs(y,x);
		dp[y]+=ksm(10,dep[y])*a[1];
		dp[x]+=dp[y];
	}
}
void dfs1(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dp[y]=dp[x]-dp[y]
		dfs1(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],len[i]=f(a[i]);
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(1,0);
	cout<<dp[1]<<endl;

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

*/