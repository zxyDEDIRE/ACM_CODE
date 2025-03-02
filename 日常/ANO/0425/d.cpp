#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll s=1,t=-1,len=0;
ll n,x;
void f(ll x)
{
	string str="";
	while(x)
	{
		if(x%2==0)str+="0";
		else str+="1";
		x>>=1;
	}
	reverse(str.begin(),str.end());
	cout<<str<<endl;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>=len)
		{
			t=max(++t,x);
			s=(1ll<<t);
		//	cout<<s<<endl;
			s|=(1ll<<x);
		//	cout<<s<<endl;
			len=x;
		}
		else
		{
			s|=(1<<x);
			len=x;
		}
	}
	cout<<s<<endl;
}
/*

8
2 0 2 2 0 4 2 4

100
101
1100
10100
10101
110000
110100
1010000
*/