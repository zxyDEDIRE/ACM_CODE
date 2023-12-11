#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
const int maxn=1e6+100;
ll n1,n2,n3;
ll a,b;
void solve()
{
	cin>>a>>b>>n1>>n2>>n3;
	int mi=a,ma=0;
	for(int i=0;i<=a;i++)
	{
		ll x=a-i;
		ll y=b-1ll*i*n3;
		if(y<0 || x*n1>y || x*n2 <y)continue;
		ll s = 1ll*x*n2-y;
		ll t = n2-n1;
		if(t!=0&&s%t!=0)continue;
		if(t==0&&s!=0)continue;
		mi=i;
		break;
	}


	for(int i=a;i>=0;i--)
	{
		ll x=a-i;
		ll y=b-1ll*i*n3;
		if(y<0 || x*n1>y || x*n2 <y)continue;
		ll s = 1ll*x*n2-y;
		ll t = n2-n1;
		if(t!=0&&s%t!=0)continue;
		if(t==0&&s!=0)continue;
		ma=i;
		break;
	}
	if(mi>ma)cout<<-1<<endl;
	else cout<<mi<<" "<<ma<<endl;
}
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	solve();
	return 0;
}