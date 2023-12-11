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
ll n;
vector<int>v;
void solve()
{
	cin>>n;
	while(n)
	{
		if(n%2==1)v.push_back(1);
		else v.push_back(0);
		n>>=1;
	}
	for(int i=v.size()-1;i>=0;i--)
		if(v[i])cout<<2;
		else cout<<0;
	cout<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}