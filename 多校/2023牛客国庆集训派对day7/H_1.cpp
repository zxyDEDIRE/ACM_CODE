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
ll division_block(ll k,ll n){
	ll res = 0;
	for(ll l = 1, r; l <= n; l = r + 1){
		r = n / (n / l);
		// cout<<r<<endl;
		res += n / l * (r - l + 1);
	}
	return res;
}
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll x=division_block(k,n-1)+1;
	ll y=division_block(k,n);
	cout<<x<<" "<<y<<endl;
	cout<<x+y-n<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}