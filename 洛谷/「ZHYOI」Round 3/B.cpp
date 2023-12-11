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
using ll=__int128;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll p[maxn];
int n,l,r;
ll ans=0,y;
bool check(ll mid, ll x)
{
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=(mid/p[i]);
	}
	return sum<=x;
}
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
ll bound(ll x)
{
	ll l=1,r=1e18,ans=1;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid,x))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1,x))ans++;
	return ans;
}
void dfs(int x,int fl,ll lc,bool ok)
{

	if(lc>y)return ;
	if(x==n+1){
		if(ok==0)return ;
		ans+=1ll*fl*(y/lc);
		return ;
	}
	dfs(x+1,-fl,lcm(lc,p[x]),1);
	dfs(x+1,fl,lc,ok);
}
ll f(ll x)
{
	y=bound(x);
	ans=0;
	dfs(1,-1,1,0);
	return ans;
}
void solve()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		long long x;cin>>x;
		p[i]=x;
	}
	cout<<(long long)(f(r)-f(l-1))<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}