#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll n;
ll f(ll x,ll y)
{
	return (x+y)*(x*x+y*y);
}


int main()
{
	cin>>n;
	ll num=1;
	while(f(1,num-1)<n)num++;
	cout<<f(1,num-1)<<endl;
	cout<<num<<endl;
	ll l=1;
	while(f(l,num-l)>n&&l<=(num/2)){
		cout<<f(l,num-l)<<endl;
		l++;
	}
	cout<<f(2,num-2);
}
