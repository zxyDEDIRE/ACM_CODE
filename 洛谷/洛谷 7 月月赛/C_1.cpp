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
int dep[maxn];
int len[maxn];
ll ans[maxn];
ll dis[maxn];
ll dp[maxn];
ll a[maxn];
int n;
int f(int x){
	if(x==0)return 1;
	int cnt=0;while(x){x/=10;cnt++;}return cnt;}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
void dfs1(int x)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		dfs1(y);
		siz[x]+=siz[y];
		(ans[x]+=mull(ans[y],ksm(10,len[x])))%=mod;
	}
	(ans[x]+=mull(a[x],siz[x]))%=mod;
}
void dfs2(int x)
{
	for(auto y:v[x])
	{
		(ans[y]+=((((ans[x]-mull(ans[y],ksm(10,len[x]))+mod)%mod -mull(siz[y],a[x])+mod)%mod)*ksm(10,len[y]))%mod)%=mod;
		(ans[y]+=mull(n-siz[y],a[y]))%=mod;


		// ans[y]+=((ans[x]-mull(ans[y],ksm(10,len[x]))+mod)%mod-mull(siz[y],a[x])+mod)%mod*ksm(10,len[y]);
		// ans[y]%=mod;
		// ans[y]+=mull(n-siz[y],a[y]);
		// ans[y]%=mod;
		dfs2(y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],len[i]=f(a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	ll res=0;
	for(int i=1;i<=n;i++){
		res+=ans[i];
		res%=mod;
	}
	cout<<res<<endl;
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