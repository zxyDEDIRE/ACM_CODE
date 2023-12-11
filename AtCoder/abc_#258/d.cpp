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
ll dp[maxn];
ll p[maxn];
ll a[maxn],b[maxn];
ll n,x;
ll mi=6e18;
void solve()
{
	cin>>n>>x;
	p[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		p[i]=a[i]+b[i]+p[i-1];
		if(x-i+1>=0)
		mi=min(mi,p[i-1]+a[i]+b[i]*(x-i+1));
	}
	cout<<mi<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}