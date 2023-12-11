#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn],sum[maxn];
ll n,k,ans;
void solve()
{
	cin>>n>>k;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=p[i]+sum[i-1];
		ll x=k-sum[i];
		ans+=max(0ll,x/i)+(x>=0?1ll:0ll);
	}
	cout<<ans<<endl;
}
int main(){
	int __;
	cin>>__;
	while(__--){
		solve();
	}
}