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
int p[maxn];
bitset<maxn>vis;
int n;
void solve()
{
	cin>>n;
	vis.reset();
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=n;i>=1;i--)
	{
		if(vis[p[i]])
		{
			cout<<i<<endl;
			return ;
		}
		vis[p[i]]=1;
	}
	cout<<0<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}