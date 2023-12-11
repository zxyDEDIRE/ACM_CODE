#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int main()
{
	int s,v,ans=10;
	cin>>s>>v;
	ans+=(s+v-1)/v;

	int x=8*60;
	if(x>=ans)
	{
		x-=ans;
		int a=x/60;
		int b=x%60;
		if(a<=9)cout<<0<<a<<":";
		else cout<<a<<":";

		if(b>=10)cout<<b<<endl;
		else cout<<0<<b<<endl;
	}
	else
	{
		x+=24*60;
		x-=ans;
		int a=x/60;
		int b=x%60;
		if(a<=9)cout<<0<<a<<":";
		else cout<<a<<":";

		if(b>=10)cout<<b<<endl;
		else cout<<0<<b<<endl;
	}
}