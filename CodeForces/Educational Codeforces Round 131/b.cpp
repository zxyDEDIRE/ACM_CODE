/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	bitset<maxn>vis;
	int j=1;
	cout<<2<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int s=i;
		while(s<=n)
		{
			cout<<s<<" ";
			vis[s]=1;
			s*=2;
		}
	}
	cout<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}