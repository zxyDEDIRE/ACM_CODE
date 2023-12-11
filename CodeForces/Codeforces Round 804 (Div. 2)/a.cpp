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
ll n;
void solve()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<n/2<<" "<<0<<" "<<0<<endl;
	}
	else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
101
000

11
01
*/