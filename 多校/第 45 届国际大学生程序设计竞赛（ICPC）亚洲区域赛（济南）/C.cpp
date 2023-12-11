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
void solve()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll ans=0;

	ll mi;
	mi=min(a,b);
	ans+=mi*2;
	a-=mi;
	b-=mi;

	// cout<<ans<<endl;
	// cout<<a<<endl;
	if(a)
	{
		if(a%3!=0)
			ans+=a-1;
		else 
			ans+=a;
	}
	

	if(b)
	{
		if(b%3==1)
			ans+=1ll*(b-1)*2;
		else ans+=1ll*b*2;

	}

	cout<<ans<<endl;

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
1 2 0
33 1
66 3
55 3


*/