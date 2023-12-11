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
using pii=pair<ll,ll>;
const int maxn=1e6;
struct node{
	ll l,r;
}p[maxn];
vector<pii>a;
vector<ll>b;
string str;
ll n,c,q;
void solve()
{
	cin>>n>>c>>q>>str;
	a.clear();
	b.clear();
	ll len=str.size();
	for(int i=1;i<=c;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.push_back({x,y});
		len+=y-x+1;
		b.push_back(len);
	}
	while(q--)
	{
		ll k,fl;
		cin>>k;
		while(k>n)
		{
			ll fl=lower_bound(b.begin(),b.end(),k)-b.begin();
			k-=(b[fl]-a[fl].second);
		}
		cout<<str[k-1]<<endl;
	}
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
1
4 3 1
mark
1 4
5 7
3 8
10
*/