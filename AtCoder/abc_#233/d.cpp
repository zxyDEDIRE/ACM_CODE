/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
map<ll,int>mp;
ll p[maxn];
ll n,k,ans;
void solve()
{
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		p[i]=p[i-1]+x;
		ans+=mp[p[i]-k];
		mp[p[i]]++;
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}