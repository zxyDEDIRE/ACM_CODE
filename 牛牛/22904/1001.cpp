/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	int n;
	priority_queue<ll,vector<ll>,greater<ll>>q;
	ll ans=0;

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		q.push(x);
	}
	while(q.size()>1)
	{
		ll x=q.top();q.pop();
		ll y=q.top();q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}