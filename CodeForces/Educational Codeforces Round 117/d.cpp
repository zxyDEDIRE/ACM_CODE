/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
const int maxn=1e6;
ll a,b,t;
bool check(ll a,ll b,ll n)
{
	if(!b)return n==a;
	if(n<=a&&n%b==a%b)return 1;
	return check(b,a%b,n);
}
void solve()
{
	cin>>a>>b>>t;
	if(a<b)swap(a,b);
	if(check(a,b,t))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
x
y
x-y
`
*/