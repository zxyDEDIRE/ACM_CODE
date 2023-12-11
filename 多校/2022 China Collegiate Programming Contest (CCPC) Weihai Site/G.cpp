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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int p[maxn];
int n,m,x;
ll f(ll l, ll r)
{
	l%=m;
	r%=m;
	if(!l)l=m;
	if(!r)r=m;
	return p[r]-p[l-1];
}
void solve()
{
	cin>>x>>n;
	m=pow(2,ceil(1.0*log2(x)));
	// cout<<m<<endl;
	for(int i=1;i<=m;i++)
	{
		p[i]=(gcd((x^(1ll*x*i)),x)==1);
		// cout<<i<<" "<<p[i]<<endl;
		p[i]+=p[i-1];
	}
	// cout<<endl;
	// for(int i=1;i<=m;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
	while(n--)
	{
		ll l,r;
		cin>>l>>r;
		ll ans=0;
		ll _l=l%m;if(!_l)_l=m;
		ll _r=r%m;if(!_r)_r=m;
		if(_l<=_r&&r-l+1<=_r-_l+1)
		{
			ans=p[_r]-p[_l-1];
		}
		else
		{
			ans+=p[m]-p[_l-1];
			ans+=p[_r];
			ll len=r-l+1-(m-_l+1)-(_r);
			ans+=1ll*len/m*p[m];
		}
		cout<<ans<<endl;
	}

}
signed main(){ 
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 1
2 1
3 4
4 1
5 8
6 1
7 8
8 1
9 16
11 16
12 4
13 16


4
1 2 3 4  5 6 7 8
  1 1 1  1 1 1 

*/