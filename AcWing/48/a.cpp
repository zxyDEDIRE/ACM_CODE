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
void solve()
{
	int n,m;
	cin>>n>>m;
	int l=n,r=100000;
	int ans=l;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(mid<=(n+((mid-1)/m)))ans=mid,l=mid;
		else r=mid;
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}