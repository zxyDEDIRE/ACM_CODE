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
ll n;
bool su(ll x)
{
	if(x==1)return 0;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	ll tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
void solve()
{
	cin>>n;
	if(su(n-6)&&su(n))cout<<"Yes\n"<<n-6<<endl;
	else if(su(n+6)&&su(n))cout<<"Yes\n"<<n+6<<endl;
	else
	{
		for(int i=n;;i++)
		{
			if(su(i-6)&&su(i))
			{
				cout<<"No\n"<<i<<endl;
				return ;
			}

			if(su(i+6)&&su(i))
			{
				cout<<"No\n"<<i<<endl;
				return ;
			}
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}