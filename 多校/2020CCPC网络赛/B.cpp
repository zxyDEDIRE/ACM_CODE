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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

int ksc(int x, int y, int mod){    return (x * y - (int)((long double)x / mod * y) * mod + mod) % mod;}
ll prime[maxn], id1[maxn], id2[maxn], flag[maxn], ncnt, m;
ll g[maxn], sum[maxn], a[maxn], T, n;
inline int ID(ll x){    return x <= T ? id1[x] : id2[n / x];}
inline ll calc(ll x){    return x * (x + 1) / 2 - 1;}
inline ll f(ll x){    return x;}
inline void init()
{
    T = sqrt(n + 0.5);
    for (int i = 2; i <= T; i++){
        if (!flag[i])
            prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
        for (int j = 1; j <= ncnt && i * prime[j] <= T; j++){
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (ll l = 1; l <= n; l = n / (n / l) + 1){
        a[++m] = n / l;
        if (a[m] <= T)
            id1[a[m]] = m;
        else
            id2[n / a[m]] = m;
        g[m] = calc(a[m]);
    }
    for (int i = 1; i <= ncnt; i++)
        for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++)
            g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
}
inline void clear()
{
	ncnt = m = 0;
}
// 1 - x 之间的质数
inline ll solve(ll x)
{
    if (x <= 1)
        return x;
    return n = x, init(), g[ID(n)];
}
ll ksm(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void solve()
{
	long long n,mod;
	cin>>n>>mod;
	clear();
	if(n==1){
		cout<<0<<'\n';return;
	}
	__int128 ans=(solve(n+1)+mod-2)%mod;
	long long qr=(n+4)%mod*(n-1)%mod*ksm(2,mod-2,mod)%mod;
	ans=(ans%mod+qr+mod)%mod;
	cout<<(long long)ans<<'\n';
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}