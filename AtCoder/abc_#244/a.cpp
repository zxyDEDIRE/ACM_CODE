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
ll n;
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b);
		p>>=1;
		b=(b*b);
	}
	return res;
}
void solve()
{
	ll n;
	cin>>n;
	ll a=fp(2,31);
	if(n>=(-a)&&n<=(a-1))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}