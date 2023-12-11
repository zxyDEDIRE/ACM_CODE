/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
map<ll,ll>ma;
map<ll,ll>mi;
map<ll,ll>vis;
ll n,q;
void solve()
{
	cin>>n>>q;
	ma.clear();
	mi.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		ma[p[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		mi[p[i]]=i;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int a=mi[x];
		int b=ma[y];
		if(mi[x]==0||ma[y]==0)cout<<"No\n";
		else
		{
			if(a<b)cout<<"Yes\n";
			else cout<<"No\n";
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