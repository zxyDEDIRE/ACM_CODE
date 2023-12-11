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
ll p[111];
ll n,m;
void solve()
{
	cin>>n>>m;
	if(n%m==0){cout<<"0\n";return ;}
	n%=m;
	ll g=__gcd(n,m);
	ll _m=m;
	n/=g;
	m/=g;
	ll fl=log2(m);
	if((1ll<<fl)!=m){
		cout<<"-1\n";
		return ;
	}
	memset(p,0,sizeof p);
	for(int i=0;i<fl;i++)
	{
		if(n&(1ll<<i))
			p[i]++;
	}
	for(int i=0;i<=fl;i++)
		p[i]*=_m;
	ll ans=0;
	for(int i=0;i<fl;i++)
	{
		ans+=p[i]/2;
		p[i+1]+=p[i]/2;
	}
	cout<<ans<<endl;
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
0.2

0.5
0.25
0.125
0.0625
0.03125



*/