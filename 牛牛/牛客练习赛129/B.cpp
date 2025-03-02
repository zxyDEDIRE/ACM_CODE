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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

const ll mod=1e9+7;
const int M = 1e6+10;
int ff[M+5];  //打表，记录n!，避免重复计算
 
//求最大公因数
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b){
    if(b==0){x=1;y=0;}
    else{Extended_gcd(b,a%b);long t=x;x=y;y=t-(a/b)*y;}
}
//计算不大的C(n,m)
int C(int a,int b){
    if(b>a)return 0;b=(ff[a-b]%mod*ff[b])%mod;a=ff[a];
    int c=gcd(a,b);a/=c;b/=c;Extended_gcd(b,M);x=(x+mod)%mod;
    x=(x*a)%mod;return x;
}
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;int a,b;
    while(m||n){a=n%mod;b=m%mod;n/=mod;m/=mod;
        ans=(ans*C(a,b))%mod;}
    return ans;
}
int A(int n,int m){return (Combination(n,m)*ff[m])%mod;}

ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}


ll n,m;
ll f(ll x, ll y)
{
	return ksm(ksm(2,x),y)%mod;
}
void solve()
{
	cin>>n>>m;
	ll cnt=f(n,m);
	cnt = cnt - n;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		ll x = f(n-i,m)*C(n,i);
		// x%=mod;
		cout<<x<<endl;
		cnt=(cnt-x%mod+mod)%mod;
	}
	cout<<cnt<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
    ff[0]=1;
    for(int i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%mod;


	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
1
2

1
2
2

2
1
1

2
2
1


1 2
1
2


1 
1 2


1
2
3
1 2
2 3
1 3
1 2 3
*/