/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn],f[10000];
ll n;
ll h(ll x)
{
	ll cnt=0;
	while(x){
		cnt++;
		x>>=1;
	}
	return cnt;
}
void solve()
{
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		ll t=h(p[i]);
		ans+=f[t];
		f[t]++;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
111
110

110
001
*/