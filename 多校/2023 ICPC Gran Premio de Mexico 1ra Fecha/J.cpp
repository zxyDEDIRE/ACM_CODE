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
const int mod=1e9+7;
const int maxn=1e6+100;
ll sum[maxn];
ll a[maxn];
ll p[maxn];
int n,q;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		sum[i]=sum[i-1]+p[i];sum[i]%=mod;
		a[i]=a[i-1]+p[i]*p[i];a[i]%=mod;
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ll x=sum[r]-sum[l-1];x=(x%mod+mod)%mod;
		ll ans=x*x%mod-(a[r]-a[l-1]);ans=(ans%mod+mod)%mod;
		ans=(ans*ksm(2,mod-2))%mod;
		cout<<ans<<endl;
	}
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
1*(1+2)
2*(1+2)
*/