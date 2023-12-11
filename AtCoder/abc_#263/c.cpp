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
int p[100];
int n,m;
void dfs(int x,int step)
{
	if(step>n)
	{
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=x+1;i<=m;i++)
	{
		p[step]=i;
		dfs(i,step+1);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		p[1]=i;
		dfs(i,2);
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}