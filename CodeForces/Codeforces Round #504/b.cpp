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
ll n,k;
void solve()
{
	cin>>n>>k;
	if(n+n-1<k){
		cout<<0<<endl;
		return ;
	}
	ll r=min(n,k-1);
	ll l=k-r;
	ll len=r-l+1; 
	cout<<len/2<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3 4 5 6
*/