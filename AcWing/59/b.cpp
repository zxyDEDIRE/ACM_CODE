/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=unsigned long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n;
void solve()
{
	cin>>n;
	if(n%2==0)cout<<n/2<<endl;
	else
	{
		for(ll i=3;i*i<=n;i++)
		{
			if(n%i==0)
			{
				n-=i;
				cout<<1+n/2<<endl;
				return ;
			}
		}
		cout<<1<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}