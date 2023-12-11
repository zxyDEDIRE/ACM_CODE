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
map<string,int>mp;
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		mp[str]++;
		if(mp[str]==1)cout<<str<<endl;
		else cout<<str<<"("<<mp[str]-1<<")"<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}