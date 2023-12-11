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
vector<int>v[maxn];
int num[maxn];
int n,ans;
void dfs(int x,int deep)
{
	if(x==n)
	{
		ans=deep;
	}
	for(auto y:v[x])
		dfs(y,deep+1);
}
void solve()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}