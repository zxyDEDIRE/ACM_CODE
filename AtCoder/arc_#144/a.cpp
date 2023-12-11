/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
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
	cin>>n;
	cout<<n*2<<endl;
	vector<int>v;
	while(n)
	{
		int t=min(n,4);
		v.push_back(t);
		n-=t;
	}
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	cout<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/