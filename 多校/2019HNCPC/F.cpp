
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long long n,a,b,c,d;
const int mod=1e9+7;
void solve()
{
	long long ans=0;
	ans+=((n)*(n-1)/2)%mod*a%mod*b%mod;
	ans%=mod;
	ans+=((n)*(n-1)/2)%mod*c%mod*b%mod;
	ans%=mod;
	ans+=((n)*(n-1)/2)%mod*c%mod*d%mod;
	ans%=mod;
	ans+=((n)*(n-1)/2)%mod*a%mod*d%mod;
	ans%=mod;
	ans+=n*((a+b+c+d)%mod)%mod;
	ans%=mod;
	ans++;
	ans%=mod;
	cout<<ans<<'\n';
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>a>>b>>c>>d)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}