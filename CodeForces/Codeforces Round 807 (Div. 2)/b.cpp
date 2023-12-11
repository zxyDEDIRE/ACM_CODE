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
ll n,ans;
void solve()
{
	cin>>n;
	ans=0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i<n)
		{
			ans+=p[i];
			if(p[i]==0&&flag)ans++;
			if(p[i]!=0)flag=1;
		}
	}
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