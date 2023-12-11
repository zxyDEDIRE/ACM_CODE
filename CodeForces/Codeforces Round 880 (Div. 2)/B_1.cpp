#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		ll n,k,g;
		cin>>n>>k>>g;
		if(g==1||g==2){
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		if(k*g>(ceill(0.5*g)-1)*n)
		{
			ans+=(n-1)*(ceill(0.5*g)-1);
			ll r=(k*g-ans)%g;
			if(r<ceill(0.5*g))ans+=r;
			else
			{
				if(ans>=(g-r))ans=ans-(g-r);
				else ans=max((g-(r+ans)),ans-(g-r));
			}
		}
		else ans=k*g;
		cout<<ans<<"\n";
	}
	return 0;
}