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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
const int mod=1e9+7;
int n;
void solve()
{
	cin>>n;
	ll ans=1;
	for(ll i=3;i<=2*n;i++)
		(ans*=i)%=mod;
	cout<<ans<<endl;

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
1 2 3 4


1 2 4 3
1 4 2 3
4 1 2 3

1 3 2 4
3 1 2 4

2 1 3 4

1 3 2 4

*/