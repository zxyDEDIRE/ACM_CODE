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
const int mod=1e9+7;
const int maxn=1e6;
int p[maxn];
int n,m;
ll A(ll s,ll t)
{
	if(s<=0||t<=0)return 1ll;
	ll ans=1;
	ll x=s;
	for(int i=1;i<=t;i++)
	{
		ans*=x;
		ans%=mod;
		x--;
	}
	return ans%mod;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==0)m=i;
	}

	bitset<maxn>vis;
	for(int i=m;i>=1;i--)
		vis[p[i]]=1;
	int t=0;
	while(vis[t])t++;t--;
	int sa=m-t;



}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}