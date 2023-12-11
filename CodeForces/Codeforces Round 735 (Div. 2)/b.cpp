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
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll mi=-1e18;
	for(int i=max(1,n-2*k);i<=n;i++)
		for(int j=i+1;j<=n;j++)
			mi=max(mi,1ll*i*j-k*(p[i]|p[j]));
	cout<<mi<<endl;
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
i*j-k*(a[i]|a[j])

6 6
3 2 0 0 5 6 1 1
12
7*8-6*(1|1)
56-6
50
*/