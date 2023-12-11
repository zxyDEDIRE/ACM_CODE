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
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int>v[n+1];
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<v[j][i]<<" ";
		cout<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}