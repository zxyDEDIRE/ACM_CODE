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
ll n,k;
void A()
{
	if(k==1)cout<<n<<" ";
	else if(k>=(2*n+1))cout<<0<<" ";
	else {
		double yu=n-0.5*(k-1)+0.1;
		double now=yu-floor(yu);
		if(now>=0.5)cout<<ceil(yu)<<" ";
		else cout<<floor(yu)<<" ";
	}
}
void B()
{
	if(k==1)cout<<n<<endl;
	else if(k>2*n)cout<<n*2<<endl;
	else {
		// cout<<(k-1+ceil(n-0.5*(k-1)))<<endl;
		ll ans=k-1;
		double yu=n-0.5*(k-1);
		ans+=floor(yu);
		yu-=floor(yu);
		if(yu>=0.5)ans++;
		cout<<ans<<endl;
	}
}
void solve()
{
	cin>>n>>k;
	A();
	B();
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
/*
0.4999999
0.4999999
0.4999999
0.4999999
0.4999999
3.11111


*/