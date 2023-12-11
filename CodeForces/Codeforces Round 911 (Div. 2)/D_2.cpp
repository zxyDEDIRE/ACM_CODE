// #pragma GCC optimize(2)
// #pragma GCC optimize(3,"Ofast","inline")
// #include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define endl "\n"
using ll=long long;
const int maxn=1e6+100;
int gcd(int a, int b) {
	int az = __builtin_ctz(a);
	int bz = __builtin_ctz(b);
	int z = min(az, bz);
	b >>= bz;
	while (a) {
		a >>= az;
		int diff = a - b;
		az = __builtin_ctz(diff);
		b = min(a, b), a = abs(diff);
	}
	return b << z;
}
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	n--;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			// cout<<p[i]<<" "<<p[j]<<" "<<__gcd(p[i],p[j])*(n-j+1)<<endl;
			ans+=__gcd(p[i],p[j])*(n-j+1);
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