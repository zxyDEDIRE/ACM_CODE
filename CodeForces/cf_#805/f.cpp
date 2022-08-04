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
vector<int>v[maxn];
map<int,int>mp;
ll a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	ll mi=1e10,ma=-1e10;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]=1;
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		ll s;
		s=b[i];
		while(s>=mi)
		{
			if(mp[s])v[i].push_back()
		}
	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}