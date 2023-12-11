#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll n,q,sum=0;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
 
	ll ma=p[1],mo=0;
	for(int i=2;i<=n;i++)
	{
		if(p[i]<=ma)
		{
			mo+=ma-p[i];
		}
		else
		{
			ll t=p[i]-ma;
			if(t<=mo)mo-=t;
			else
			{

				t-=mo;
				mo=0;

				ll k=(t-1)/i+1;
				mo=k*i;
				mo-=t;
				ma+=k;
			}
		}
	}


	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		if(x<ma){
			cout<<-1<<"\n";
			continue;
		}
		

		ll ans=(sum+x-1)/x;
		cout<<ans<<endl;

	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
/*

*/