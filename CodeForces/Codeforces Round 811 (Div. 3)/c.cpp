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
int n;
void solve()
{
	vector<int>v;
	cin>>n;
	for(int i=9;i>=1;i--)
	{
		if(n>=i)v.push_back(i),n-=i;
	}
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}