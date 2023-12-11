/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll f(ll x)
{
	return x*x+2*x+3;
}
void solve()
{
	ll n;
	cin>>n;
	ll m=f(f(f(n)+n)+f(f(n)));
	cout<<m<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}