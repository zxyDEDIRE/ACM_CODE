#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5;
int n;

void doit(int x)
{
	int y=x*x*x;
	string str="",a="";
	while(y)
	{
		int t=y%n;
		if(t<=9)str=str+(char)('0'+t);
		else
		{
			t-=10;
			str=str+(char)('A'+t);
		}
		y/=n;
	}
	int l=0,r=str.size()-1;
	while(l<=r)
	{
		if(str[l]!=str[r])return ;
		l++,r--;
	}
	while(x)
	{
		int t=x%n;
		if(t<=9)a=a+(char)('0'+t);
		else
		{
			t-=10;
			a=a+(char)('A'+t);
		}
		x/=n;
	}
	cout<<a<<" "<<str<<endl;
}

signed main()
{
	for(n=2;n<=16;n++)
	{
		cout<<n<<endl;
		for(int i=1;i<=300;i++)doit(i);
		cout<<endl;
	}
}
/*
7
1101

*/
